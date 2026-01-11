/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:09:57 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/08 12:37:02 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_loop(int fd, char *file);
int		is_newline(char *s);
int		find_new_line(char *str);
char	*join_free(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*free_and_null(char **s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup_gnl(char *src);
int		ft_strlen_int(const char *s);

#endif
