/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:18:29 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/19 14:41:02 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	int		fd;
	t_list	*map;
	t_game	game;
	char	**tmp_map;

	ft_bzero(&game, sizeof(t_game));
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
			return (free_all(map), 0);
		if (!playable_map(tmp_map, &game))
			ft_printf("Error:\nNot a playable map\n");
		init_win(&game, map);
	}
	return (0);
}

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
// 	int		fd;
// 	char *line;
// 	(void)argc;
// 	fd = open(argv[1], O_RDONLY);
// 	line = get_next_line(fd);
// 	free(line);
// 	line = NULL;
// 	get_next_line(-1);
// 	return 0;
// }

