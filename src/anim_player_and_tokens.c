/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_player_and_tokens.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:01:25 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/02 16:36:16 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	anim(t_game *game, t_anim *anim)
{
	if (anim->frames)
		free_lst_anim(&anim->frames, game->win.mlx);
	slices(game, anim);
}

int	update_tokens(t_anim *anim, t_map *map, t_point *p, t_point x)
{
	static clock_t	last_update[2] = {0, 0};
	clock_t			cur_time;
	clock_t			elapsed_time;
	int				i;

	cur_time = clock();
	elapsed_time = (cur_time - last_update[x.y]) * 1000 / CLOCKS_PER_SEC;
	if (elapsed_time < (1000 / FPS))
		return (1);
	last_update[x.y] = cur_time;
	if (!anim->frames)
		return (1);
	i = 0;
	anim->cur_frame++;
	anim->cur_frame %= ft_lstsize(anim->frames);
	while (i < x.x)
	{
		if (map->map[p[i].y][p[i].x] == BAD
			|| map->map[p[i].y][p[i].x] == TOKEN)
			update_anim(anim, (t_point){p[i].x, p[i].y});
		i++;
	}
	return (0);
}

int	update_player(t_anim *anim, t_point p)
{
	static clock_t	last_update = 0;
	clock_t			current_time;
	clock_t			elapsed_time;

	current_time = clock();
	elapsed_time = (current_time - last_update) * 1000 / CLOCKS_PER_SEC;
	if (elapsed_time < (1000 / FPS))
		return (1);
	last_update = current_time;
	if (!anim->frames)
		return (1);
	anim->cur_frame++;
	anim->cur_frame %= ft_lstsize(anim->frames);
	update_anim(anim, p);
	return (0);
}

void	side_moves(int dir, t_img bigfra, t_img *frame, t_slice px)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = px.pos.y;
	j = px.pos.x;
	x = px.w;
	y = px.h;
	if (dir == KEY_D || dir == RIGHT)
		put_px_img(*frame, j, i, get_px_img(&bigfra, x + j, y + i));
	if (dir == KEY_A || dir == LEFT)
		put_px_img(*frame, SIZE - j - 1, i, get_px_img(&bigfra, x + j, y + i));
	if (dir == KEY_W || dir == UP)
		put_px_img(*frame, i, SIZE - j - 1, get_px_img(&bigfra, x + j, y + i));
	if (dir == KEY_S || dir == DOWN)
		put_px_img(*frame, i, j, get_px_img(&bigfra, x + j, y + i));
}
