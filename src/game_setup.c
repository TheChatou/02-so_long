/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:47:39 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/24 14:01:41 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	set_game(t_game *game, char *map_path)
{
	game->w = game->map.size.x * SIZE;
	game->h = game->map.size.y * SIZE;
	game->map.tk_cc = 0;
	map_cpy(&game->map, map_path);
	count_t_tk(&game->map);
	find_player(&game->map);
	set_xpm(game);
	set_anim(&game->sta_pl, 7, PA_PLAYER, (t_slice){{96, 0}, (SIZE * 7), SIZE});
	set_anim(&game->walk_pl, 3, PA_PLAYER, (t_slice){{0, 0}, (SIZE * 3), SIZE});
	set_anim(&game->good_tk, 8, PA_TOKENS,
		(t_slice){{0, 32}, (SIZE * 8), (SIZE * 2)});
	set_anim(&game->bad_tk, 8, PA_TOKENS,
		(t_slice){{0, 0}, (SIZE * 8), (SIZE * 2)});
}

void	set_anim(t_anim *anim, int frame_cc, char *path, t_slice slice)
{
	anim->frame_cc = frame_cc;
	anim->file_path = path;
	anim->slice = slice;
}

void	*set_player(t_game *game, t_point p)
{
	t_img		*img;

	game->xpm_switch = game->xpm_ptr[11];
	game->map.pl_pos.x = p.x;
	game->map.pl_pos.y = p.y;
	if (game->moves == 0)
	{
		anim(game, &game->sta_pl);
		img = (t_img *)game->sta_pl.frames->content;
		return (img->xpm_ptr);
	}
	else
	{
		anim(game, &game->walk_pl);
		img = (t_img *)game->walk_pl.frames->content;
		return (img->xpm_ptr);
	}
}

void	set_xpm(t_game *game)
{
	int		i;
	int		s;

	s = SIZE;
	i = 0;
	while (i < 14)
	{
		game->xpm_ptr[i] = mlx_xpm_file_to_image(game->win.mlx,
				game->xpm_paths[i], &s, &s);
		if (!game->xpm_ptr[i])
		{
			ft_printf("Couldn't reach xpm file\n");
			destroy_game(game);
		}
		if (game->xpm_paths[i] == NULL)
			ft_printf("%s Couldn't find a sprite path\n",
				game->xpm_paths[i]);
		i++;
	}
}

void	*set_token(t_game *game, char c)
{
	t_img		*img;

	if (c == BAD)
	{
		if (!game->good_tk.frames)
			anim(game, &game->good_tk);
		img = (t_img *)game->good_tk.frames->content;
	}
	if (c == TOKEN)
	{
		if (!game->bad_tk.frames)
			anim(game, &game->bad_tk);
		img = (t_img *)game->bad_tk.frames->content;
	}
	return (img->xpm_ptr);
}
