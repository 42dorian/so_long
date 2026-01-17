/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:18:29 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/17 14:12:36 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	int		fd;
	t_list	*map;
	char **map_arr;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	map = read_map(fd);
	// printf_map(map);
	if (validate_map(map))
	{
		map_arr = store_map(map);
		if(!map_arr)
			return(free_all(map), 0);
	}
	else
		ft_printf("NOT NICE\n");
	free_all(map);
	return (0);
}

void	printf_map(t_list *head)
{
	while (head)
	{
		ft_printf("%s\n", head->content);
		head = head->next;
	}
}
