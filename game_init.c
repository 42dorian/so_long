/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:28:03 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/21 13:02:28 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_win(t_game *game, t_list *map)
{
	game->collected_coins = 0;
	game->map_h = count_nodes(map);
	game->map_w = ft_strlen(map->content);
	game->map = store_map(map);
	if (!game->map)
		return (free_all(map), 0);
	free_all(map);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_strs(game->map, game->map_h), 0);
	load_images(game);
	game->win = mlx_new_window(game->mlx, game->map_w * 64, game->map_h * 64,
			"so_long");
	if (!game->win)
		kill_game(game);
	mlx_loop_hook(game->mlx, update_animation, game);
	mlx_key_hook(game->win, handle_input, game);
	mlx_hook(game->win, 17, 0L, handle_x, game);
	mlx_loop(game->mlx);
	return (1);
}

void	load_images(t_game *g)
{
	int	w;
	int	h;

	g->wall = mlx_xpm_file_to_image(g->mlx, "xpms/wall.xpm", &w, &h);
	g->player[0] = mlx_xpm_file_to_image(g->mlx, "xpms/p_r.xpm", &w, &h);
	g->player[1] = mlx_xpm_file_to_image(g->mlx, "xpms/p_l.xpm", &w, &h);
	g->floor = mlx_xpm_file_to_image(g->mlx, "xpms/bg_1.xpm", &w, &h);
	g->door = mlx_xpm_file_to_image(g->mlx, "xpms/door.xpm", &w, &h);
	g->coin_frames[0] = mlx_xpm_file_to_image(g->mlx, "xpms/c0.xpm", &w, &h);
	g->coin_frames[1] = mlx_xpm_file_to_image(g->mlx, "xpms/c1.xpm", &w, &h);
	g->coin_frames[2] = mlx_xpm_file_to_image(g->mlx, "xpms/c2.xpm", &w, &h);
	g->coin_frames[3] = mlx_xpm_file_to_image(g->mlx, "xpms/c3.xpm", &w, &h);
	g->coin_frames[4] = mlx_xpm_file_to_image(g->mlx, "xpms/c2.xpm", &w, &h);
	g->coin_frames[5] = mlx_xpm_file_to_image(g->mlx, "xpms/c1.xpm", &w, &h);
	g->curr_frame = 0;
	g->loop_counter = 0;
	g->p_dir = 1;
	g->moves_count = 0;
	if (!check_images(g))
	{
		ft_printf("Error\n");
		kill_game(g);
	}
}

void	render_all(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g->map[y])
	{
		while (g->map[y][x])
		{
			img_to_win(g, g->floor, x * 64, y * 64);
			if (g->map[y][x] == '1')
				img_to_win(g, g->wall, x * 64, y * 64);
			else if (g->map[y][x] == 'P')
				img_to_win(g, g->player[g->p_dir], x * 64, y * 64);
			else if (g->map[y][x] == 'C')
				img_to_win(g, g->coin_frames[g->curr_frame], (x * 64) + 7, (y
						* 64) + 7);
			else if (g->map[y][x] == 'E')
				img_to_win(g, g->door, x * 64, y * 64);
			x++;
		}
		x = 0;
		y++;
	}
}

int	img_to_win(t_game *game, void *img_ptr, int x, int y)
{
	return (mlx_put_image_to_window(game->mlx, game->win, img_ptr, x, y));
}

int	update_animation(t_game *game)
{
	game->loop_counter++;
	if (game->loop_counter > 10000)
	{
		game->curr_frame++;
		if (game->curr_frame >= 6)
			game->curr_frame = 0;
		game->loop_counter = 0;
		render_all(game);
	}
	return (0);
}
