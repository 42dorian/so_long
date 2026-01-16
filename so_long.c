/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:18:29 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/16 19:50:35 by dabdulla         ###   ########.fr       */
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

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	map = read_map(fd);
	printf_map(map);
	if (validate_map(map))
		ft_printf("NICE\n");
	else
		ft_printf("NOT NICE\n");
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
