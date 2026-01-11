/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:18:29 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/08 12:30:02 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

#include <mlx.h>
#include <fcntl.h>
#include "so_long.h"

int main(int argc, char const *argv[])
{
    int fd;
    char *s;
    
    if (argc != 2)
        return (0);
    
    fd = open(argv[1], O_RDONLY);
    while ((s = get_next_line(fd)))
    {
        ft_printf("%s", s);
        free_and_null(&s);
    }
    
    return 0;
}
