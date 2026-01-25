/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:18:29 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/25 19:11:04 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	int		fd;
	t_list	*map;
	t_game game;
	char **tmp_map;
	
	game.map = NULL;
	tmp_map = NULL;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	map = read_map(fd);
	if (validate_map(map))
	{
		tmp_map = store_map(map);
		if(!tmp_map)
			return(0);
		if(!playable_map(tmp_map, &game))
			ft_printf("Error:\nNot a playable map\n");
	}
	free(tmp_map);
	game.map = store_map(map);
	game.map_h = count_nodes(map);
	game.map_w = ft_strlen(map->content);
	init_win(&game);
	free_all(map);
	free(game.map);
	return (0);
}

void	printf_map(t_list *head)
{
	while (head)
	{
		ft_printf("%s\n", head->content);
		head = head->next;
	}
}

void print_map_arr(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}
