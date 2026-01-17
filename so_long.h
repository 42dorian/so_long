/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:15:53 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/17 15:40:04 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "libft/libft.h"

typedef struct s_find
{
	int				coins_found;
	int				exit_found;
}					t_find;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list				*read_map(int fd);
int					valid_chars(t_list *head);
int					free_all(t_list *head);
int					valid_rectangle(t_list *head);
int					validate_map(t_list *head);
char				**store_map(t_list *head);
int					count_nodes(t_list *head);
int					valid_required_chars(t_list *head, int e, int p, int c);
int					valid_walls(t_list *head);
int					validate_map(t_list *head);
void	free_strs(char **strs, int i);
void	playable_map(char **map, int x, int y, t_find *coins_exit, int total_c)

// testing
void				printf_map(t_list *head);

#endif