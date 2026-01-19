/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:18:29 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/19 15:23:24 by dabdulla         ###   ########.fr       */
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
	
	map_arr = NULL;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	map = read_map(fd);
	if (validate_map(map))
	{
		map_arr = store_map(map);
		if(!map_arr)
			return(0);
		ft_printf("Validated\n");
		print_map_arr(map_arr);
	}
	else
	{
		ft_printf("NOT NICE\n");
		return (0);
	}
	if(playable_map(map_arr))
		ft_printf("Playable\n");
	// free_all(map);
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

void print_map_arr(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}
