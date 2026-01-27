/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:15:53 by dabdulla          #+#    #+#             */
/*   Updated: 2026/01/27 16:08:51 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

typedef struct s_find
{
	int				coins_found;
	int				exit_found;
}					t_find;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*wall;
	void			*player[2];
	int				p_dir;
	void			*coin_frames[6];
	int				curr_frame;
	int				loop_counter;
	void			*exit;
	void			*floor;
	void			*door;
	char			**map;
	int				map_w;
	int				map_h;
	int				player_x;
	int				player_y;
	int				collectible_count;
	int				move_count;
}					t_game;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list				*read_map(int fd);
int					valid_chars(t_list *head);
void				free_all(t_list *head);
int					valid_rectangle(t_list *head);
int					validate_map(t_list *head);
char				**store_map(t_list *head);
int					count_nodes(t_list *head);
int					valid_required_chars(t_list *head, int e, int p, int c);
int					valid_walls(t_list *head);
int					validate_map(t_list *head);
void				free_strs(char **strs, int i);
int					playable_map(char **map, t_game *game);
void				map_info(char **map, int *px, int *py, int *coins);
void				fill_map(char **map, int y, int x, t_find *coins_exit);
int					init_win(t_game *game);
void				load_images(t_game *game);
void				render_all(t_game *game);
int					update_animation(t_game *game);
int					img_to_win(t_game *game, void *img_ptr, int x, int y);
int					handle_input(int keysym, t_game *game);
void				move_player(t_game *game, int x, int y);
int					check_input(int fd, int argc, char const *argv);
// testing
void				printf_map(t_list *head);
void				print_map_arr(char **map);

#endif