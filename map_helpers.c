/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:36:03 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/13 14:30:52 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(int fd)
{
	char	*line;
	size_t	line_len;

	line_len = 0;
	while ((line = get_next_line(fd)))
	{
		if (!valid_chars(line))
		{
			free_and_null(&line);
			return (0);
		}
		if (line_len == 0)
			line_len = ft_strlen(ft_strtrim(line, "\n"));
		else if (line_len != ft_strlen(ft_strtrim(line, "\n")))
		{
			free_and_null(&line);
			return (0);
		}
		free_and_null(&line);
	}
	return (1);
}

int	valid_chars(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (!ft_strchr("01CEP\n", map_line[i]))
			return (0);
		i++;
	}
	return (1);
}
