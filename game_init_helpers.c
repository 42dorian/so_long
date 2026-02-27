/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:38:22 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/27 11:12:00 by dabdulla         ###   ########.fr       */
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

int	img_to_win(t_game *game, void *img_ptr, int x, int y)
{
	return (mlx_put_image_to_window(game->mlx, game->win, img_ptr, x, y));
}

int	check_map_size(t_list *head)
{
	if (count_nodes(head) > 14 || ft_strlen(head->content) > 30)
	{
		ft_printf("Error\nMap is too large!\n");
		return (0);
	}
	return (1);
}
