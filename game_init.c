/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:28:03 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/27 12:59:52 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_win(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->map_w * 64, game->map_h * 64,
			"so_long");
	if (!game->win)
		return (0);
	load_images(game);
	mlx_loop_hook(game->mlx, update_animation, game);
	mlx_key_hook(game->win, handle_input, game);
	mlx_hook(game->win, 2, 1L << 0, handle_input, game);
	mlx_loop(game->mlx);
	return (0);
}

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->wall = mlx_xpm_file_to_image(game->mlx, "xpms/wall.xpm", &w, &h);
	game->player[0] = mlx_xpm_file_to_image(game->mlx, "xpms/p_r.xpm", &w, &h);
	game->player[1] = mlx_xpm_file_to_image(game->mlx, "xpms/p_l.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "xpms/bg_1.xpm", &w, &h);
	game->door = mlx_xpm_file_to_image(game->mlx, "xpms/door.xpm", &w, &h);
		game->coin_frames[0] = mlx_xpm_file_to_image(game->mlx, "xpms/c0.xpm", &w,
			&h);
	game->coin_frames[1] = mlx_xpm_file_to_image(game->mlx, "xpms/c1.xpm", &w,
			&h);
	game->coin_frames[2] = mlx_xpm_file_to_image(game->mlx, "xpms/c2.xpm", &w,
			&h);
	game->coin_frames[3] = mlx_xpm_file_to_image(game->mlx, "xpms/c3.xpm", &w,
			&h);
	game->coin_frames[4] = mlx_xpm_file_to_image(game->mlx, "xpms/c2.xpm", &w,
			&h);
	game->coin_frames[5] = mlx_xpm_file_to_image(game->mlx, "xpms/c1.xpm", &w,
			&h);
	game->curr_frame = 0;
	game->loop_counter = 0;
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

int	update_animation(t_game *game)
{
	game->loop_counter++;
	if (game->loop_counter > 1000)
	{
		game->curr_frame++;
		if (game->curr_frame >= 6)
			game->curr_frame = 0;
		game->loop_counter = 0;
		render_all(game);
	}
	return (0);
}