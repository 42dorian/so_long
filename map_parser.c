/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:36:03 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/01 02:40:21 by dabdulla         ###   ########.fr       */
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
		map[i] = ft_strdup(head->content);
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

int	playable_map(char **map, t_game *game)
{
	int		x;
	int		y;
	int		coins;

	game->coins_found = 0;
	game->exit_found = 0;
	map_info(map, &x, &y, &coins);
	game->player_y = y;
	game->player_x = x;
	fill_map(map, y, x, game);
	free(map);
	return (game->exit_found == 1 && game->coins_found == coins);
}

void	fill_map(char **map, int y, int x, t_game *game)
{
	if (map[y][x] == 'V' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		game->coins_found++;
	else if (map[y][x] == 'E')
	{
		game->exit_found = 1;
		return ;
	}
	map[y][x] = 'V';
	fill_map(map, y + 1, x, game);
	fill_map(map, y - 1, x, game);
	fill_map(map, y, x + 1, game);
	fill_map(map, y, x - 1, game);
}
