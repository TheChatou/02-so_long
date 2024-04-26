/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:42:30 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/24 14:00:33 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	slices(t_game *game, t_anim *anim)
{
	int	i;
	int	x;

	i = 0;
	x = anim->slice.pos.x;
	anim->w = SIZE;
	anim->h = SIZE;
	anim->cur_frame = 0;
	anim->last_updated = 0;
	while (i < anim->frame_cc)
	{
		add_frame(game, anim, (t_point){0, 0});
		anim->slice.pos.x += SIZE;
		i++;
	}
	anim->slice.pos.x = x;
}

void	add_frame(t_game *game, t_anim *anim, t_point p)
{
	t_img	*frame;

	if (!anim->bigfra.xpm_ptr)
		anim->bigfra = new_file_img(anim->file_path, game->win, anim->slice);
	frame = (t_img *) ft_calloc(sizeof(t_img), 1);
	if (!frame)
		return ;
	*frame = new_img(SIZE, SIZE, game->win);
	while (p.y < SIZE)
	{
		p.x = 0;
		while (p.x < SIZE)
		{
			if (game->moves == 0)
				put_px_img(*frame, p.x, p.y, get_px_img(&anim->bigfra,
						anim->slice.pos.x + p.x, anim->slice.pos.y + p.y));
			else
				side_moves(game->dir, anim->bigfra, frame, (t_slice){{p.x, p.y},
					anim->slice.pos.x, anim->slice.pos.y});
			p.x++;
		}
		p.y++;
	}
	ft_lstadd_back(&anim->frames, ft_lstnew(frame));
}

int	update(t_game *game)
{
	int	t_tk;
	int	t_bad;

	t_tk = game->map.t_tk;
	t_bad = game->map.t_bad;
	if (game->bad_tk.frames && game->good_tk.frames)
	{
		update_tokens(&game->good_tk, &game->map,
			game->map.tk_pos, (t_point){t_tk, 0});
		update_tokens(&game->bad_tk, &game->map,
			game->map.bad_pos, (t_point){t_bad, 1});
	}
	if (game->moves == 0)
		return (update_player(&game->sta_pl, game->map.pl_pos));
	else
		return (update_player(&game->walk_pl, game->map.pl_pos));
}

void	update_anim(t_anim *anim, t_point p)
{
	t_img	*img;

	img = (t_img *)ft_lstget(anim->frames, anim->cur_frame)->content;
	mlx_put_image_to_window(img->win.mlx, img->win.win,
		img->xpm_ptr, p.x * SIZE, p.y * SIZE);
}
