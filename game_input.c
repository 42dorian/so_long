/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:37:47 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/18 12:21:21 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_game *game)
{
	if (!game)
		return (0);
	if (keysym == ESC_KEY)
	{
		kill_game(game);
		exit(0);
	}
	if (keysym == W_KEY)
		move_player(game, 0, -1);
	else if (keysym == A_KEY)
	{
		game->p_dir = 1;
		move_player(game, -1, 0);
	}
	else if (keysym == S_KEY)
		move_player(game, 0, 1);
	else if (keysym == D_KEY)
	{
		game->p_dir = 0;
		move_player(game, 1, 0);
	}
	return (0);
}

int	handle_x(t_game *game)
{
	kill_game(game);
	exit(0);
	return (0);
}

void	move_player(t_game *game, int x, int y)
{
	int	next_y;
	int	next_x;

	next_y = game->player_y + y;
	next_x = game->player_x + x;
	if (game->map[next_y][next_x] == '1')
		return ;
	else if (game->map[next_y][next_x] == 'C')
		game->collected_coins++;
	else if (game->map[next_y][next_x] == 'E'
		&& game->collected_coins == game->coins_found)
	{
		kill_game(game);
		exit(0);
	}
	else if (game->map[next_y][next_x] == 'E'
		&& game->collected_coins != game->coins_found)
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->map[next_y][next_x] = 'P';
	game->player_y = next_y;
	game->player_x = next_x;
	render_all(game);
	game->moves_count++;
	ft_printf("Moves: %i\n", game->moves_count);
}
