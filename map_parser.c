/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:36:03 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/19 15:25:25 by dabdulla         ###   ########.fr       */
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

	i = 0;
	height = count_nodes(head);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	while (head)
	{
		map[i] = head->content;
		head = head->next;
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

int	playable_map(char **map)
{
	int x;
	int y;
	int coins;
	t_find results;
	
	results.coins_found = 0;
	results.exit_found = 0;
	map_info(map, &x, &y, &coins);
	fill_map(map, y, x, &results);
	ft_printf("Exit: %i, Coins: %i\n", results.exit_found, results.coins_found);
	if (results.exit_found == 1 && results.coins_found == coins)
		ft_printf("Playable map!\n");
	else
	{
		ft_printf("Not playable\n");
	}
	
	return(0);
}

void	fill_map(char **map, int y, int x, t_find *result)
{
	if (map[y][x] == 'V' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		result->coins_found++;
	else if (map[y][x] == 'E')
	{
		result->exit_found = 1;
		return ;
	}
	map[y][x] = 'V';
	fill_map(map, y + 1, x, result);
	fill_map(map, y - 1, x, result);
	fill_map(map, y, x + 1, result);
	fill_map(map, y, x - 1, result);
}
