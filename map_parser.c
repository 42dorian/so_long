/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:36:03 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/20 12:18:04 by dabdulla         ###   ########.fr       */
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
	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return (free_all(head), free(line), get_next_line(-1), NULL);
		new_node->content = ft_strtrim(line, "\n");
		if (!new_node->content)
			return (get_next_line(-1), free_all(head), free_all(new_node), free(line), NULL);
		new_node->next = NULL;
		if (head == NULL)
			head = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		free(line);
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
		if (!map[i])
		{
			free_strs(map, --i);
			return (0);
		}
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
	int	x;
	int	y;
	int	coins;
	int	i;

	i = 0;
	game->coins_found = 0;
	game->exit_found = 0;
	map_info(map, &x, &y, &coins);
	game->player_y = y;
	game->player_x = x;
	fill_map(map, y, x, game);
	while (map[i])
		free(map[i++]);
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
