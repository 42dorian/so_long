/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:36:03 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/17 15:40:20 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*read_map(int fd)
{
	char	*line;
	t_list	*head;
	t_list	*tail;
	t_list	*new_node;

	head = NULL;
	tail = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return (free_all(head), free(line), NULL);
		new_node->content = ft_strtrim(line, "\n");
		new_node->next = NULL;
		if (head == NULL)
			head = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		free(line);
		line = get_next_line(fd);
	}
	return (head);
}

char	**store_map(t_list *head)
{
	int		height;
	int		i;
	char	**map;
	t_list	*tmp;

	i = 0;
	height = count_nodes(head);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	while (head)
	{
		map[i] = head->content;
		tmp = head;
		head = head->next;
		free(tmp);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	count_nodes(t_list *head)
{
	int	count;

	count = 0;
	if (!head)
		return (0);
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	playable_map(char **map, int x, int y, t_find *coins_exit, int total_c)
{
	if (map[x][y] == 'V' || map[x][y] == '1')
		return ;
	if (map[x][y] == 'C')
		coins_exit->coins_found++;
	else if (map[x][y] == 'E')
	{
		coins_exit->exit_found = 1;
		return ;
	}
	map[x][y] = 'V';
	playable_map(map, x + 1, y, coins_exit, total_c);
	playable_map(map, x - 1, y, coins_exit, total_c);
	playable_map(map, x, y + 1, coins_exit, total_c);
	playable_map(map, x, y - 1, coins_exit, total_c);
	return (coins_exit->exit_found == 1 && coins_exit->coins_found == total_c);
}
