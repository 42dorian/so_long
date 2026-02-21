/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:36:39 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/21 13:02:39 by dabdulla         ###   ########.fr       */
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
	if (!ft_strnstr(argv, ".ber", ft_strlen(argv)))
	{
		ft_printf("Error\nOnly .ber allowed!");
		return (0);
	}
	if (fd <= 0)
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
	int	i;

	if (game->mlx && game->door)
		mlx_destroy_image(game->mlx, game->door);
	if (game->mlx && game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->mlx && game->player[0])
		mlx_destroy_image(game->mlx, game->player[0]);
	if (game->mlx && game->player[1])
		mlx_destroy_image(game->mlx, game->player[1]);
	if (game->mlx && game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	i = 0;
	while (i < 6)
	{
		if (game->mlx && game->coin_frames[i])
			mlx_destroy_image(game->mlx, game->coin_frames[i++]);
	}
}
