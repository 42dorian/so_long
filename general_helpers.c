/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:36:39 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/18 10:02:03 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_list *head)
{
	t_list	*tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head->content);
		free(head);
		head = tmp;
	}
}

void	free_strs(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
}

int	check_input(int fd, int argc, char const *argv)
{
	if (argc != 2)
	{
		ft_printf("Error\nOne argument required!");
		return (0);
	}
	if (fd <= 0)
		return (0);
	if (!ft_strnstr(argv, ".ber", ft_strlen(argv)))
		return (0);
	return (1);
}

void	kill_game(t_game *game)
{
	destroy_images(game);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free_strs(game->map, game->map_h);
}

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->door);
	game->door = NULL;
	mlx_destroy_image(game->mlx, game->wall);
	game->wall = NULL;
	mlx_destroy_image(game->mlx, game->floor);
	game->floor = NULL;
	mlx_destroy_image(game->mlx, game->player[0]);
	game->player[0] = NULL;
	mlx_destroy_image(game->mlx, game->player[1]);
	game->player[1] = NULL;
	mlx_destroy_image(game->mlx, game->coin_frames[0]);
	game->coin_frames[0] = NULL;
	mlx_destroy_image(game->mlx, game->coin_frames[1]);
	game->coin_frames[1] = NULL;
	mlx_destroy_image(game->mlx, game->coin_frames[2]);
	game->coin_frames[2] = NULL;
	mlx_destroy_image(game->mlx, game->coin_frames[3]);
	game->coin_frames[3] = NULL;
	mlx_destroy_image(game->mlx, game->coin_frames[4]);
	game->coin_frames[4] = NULL;
	mlx_destroy_image(game->mlx, game->coin_frames[5]);
	game->coin_frames[5] = NULL;
}
