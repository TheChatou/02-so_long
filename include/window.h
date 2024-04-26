/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:21:00 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/02 16:58:16 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <mlx.h>
# include "libft.h"
# include "ft_printf.h"
# include <game.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <time.h>

/* game_launch.c */
void			*init_game(t_game *game);
void			game_launch(t_game *game, char *map_path, char *str);
int				load_n_put(t_game *game);
void			*load_sprites(t_point i, t_game *game, void **xpm_ptr);

/* game_setup.c */
void			set_game(t_game *game, char *map_path);
void			set_anim(t_anim *anim, int frame_cc, char *path, t_slice slice);
void			*set_player(t_game *game, t_point i);
void			set_xpm(t_game *game);
void			*set_token(t_game *game, char c);

/* map_check.c */
int				map_borders(t_map *map, t_point s);
int				map_read(t_map *map, t_point s);
t_point			*map_tks_pos(t_map *map, int n, char c);
int				map_floodfill(t_map *map, t_point plr);
int				map_check(t_game *game, char *map_path);

/* map_setup.c */
void			map_cpy(t_map *map, char *map_path);
int				count_lines(char *path);
void			count_t_tk(t_map *map);
void			find_player(t_map *map);

/* player_actions.c */
int				keys_moves(int keysym, t_game *game);
int				move_player(t_game *game, t_point move, t_map *map);
void			count_moves(t_game *game, int moves);
void			up_load_free(t_game *game, t_point mv);
void			update_pos(t_game *game, t_map *map, t_point mv);

/* anim_pl_n_tks.c */
void			anim(t_game *game, t_anim *anim);
int				update_tokens(t_anim *anim, t_map *map, t_point *p, t_point x);
int				update_player(t_anim *anim, t_point p);
void			side_moves(int mvmt, t_img bigfra, t_img *frame, t_slice pix);

/* anim_utils.c*/
void			slices(t_game *game, t_anim *anim);
void			add_frame(t_game *game, t_anim *anim, t_point p);
int				update(t_game *game);
void			update_anim(t_anim *anim, t_point p);

/* utils.c */
t_img			new_img(int w, int h, t_win window);
t_img			new_file_img(char *path, t_win window, t_slice slice);
void			put_px_img(t_img img, int x, int y, int color);
unsigned int	get_px_img(t_img *img, int x, int y);
t_list			*ft_lstget(t_list *lst, int index);

/* end.c */
int				destroy_game(t_game *game);
void			destroy_window(t_win w);
void			game_over(void);
void			you_win(void);

/* free_utils.c */
void			free_map(t_map map);
void			free_xpms(void *mlx, void **xpms, int n);
void			ft_lstclear_a_xpm(t_img *img, void *mlx);
void			free_lst_anim(t_list **lst, void *mlx);
void			free_anim(t_anim *anim, void *mlx);

#endif