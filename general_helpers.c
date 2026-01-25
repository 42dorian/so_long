/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:36:39 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/24 18:10:51 by dabdulla         ###   ########.fr       */
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

int		img_to_win(t_game *game, void *img_ptr, int x, int y)
{
	return (mlx_put_image_to_window(game->mlx, game->win, img_ptr, x, y));
}