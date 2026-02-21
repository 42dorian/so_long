/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:38:22 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/21 13:02:23 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_images(t_game *game)
{
	int	i;

	i = 0;
	if (!game->wall || !game->door || !game->floor || !game->player[0]
		|| !game->player[1])
		return (0);
	while (i < 6)
	{
		if (!game->coin_frames[i])
			return (0);
		i++;
	}
	return (1);
}
