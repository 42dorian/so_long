/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:18:29 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/17 21:39:58 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	int		fd;
	t_list	*map;
	t_game	game;
	char	**tmp_map;

	game.map = NULL;
	tmp_map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (!check_input(fd, argc, argv[1]))
		return (0);
	map = read_map(fd);
	if (!map)
		return (0);
	if (validate_map(map))
	{
		tmp_map = store_map(map);
		if (!tmp_map)
			return (0);
		if (!playable_map(tmp_map, &game))
			ft_printf("Error:\nNot a playable map\n");
	}
	init_win(&game, map);
	return (0);
}
