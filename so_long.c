/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:18:29 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/13 13:47:45 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	int	fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (valid_map(fd))
		ft_printf("NICE");
	else
		ft_printf("NOT NICE");
	return (0);
}
