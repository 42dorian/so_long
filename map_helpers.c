/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:11:15 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/19 15:01:24 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_info(char **map, int *px, int *py, int *coins)
{
    int x;
    int y;

    x = 0;
    y = 0;
    *coins = 0;
    while (map[y])
    {
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                *px = x;
                *py = y;
            }
            if (map[y][x] == 'C')
            {
                *coins += 1;
                ft_printf("Found a coin at [%d][%d]. Total so far: %d\n", y, x, coins);
            }
            x++;
        }
        x = 0;
        y++;
    }
}