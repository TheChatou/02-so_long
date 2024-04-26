/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_launch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:35:10 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/02 16:06:36 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	*init_game(t_game *game)
{
	*game = (t_game){0};
	*game = (t_game){.xpm_paths = {PA_0, PA_1, PA_2, PA_3, PA_4, PA_5,
		PA_6, PA_7, PA_8, PA_9, PA_10, PA_11, PA_12, PA_13}};
	game->win.mlx = mlx_init();
	if (!game->win.mlx)
		return (ft_putstr_fd("Error mlx\n", 2), destroy_game(game), NULL);
	return (game);
}

void	game_launch(t_game *game, char *map_path, char *str)
{
	if (!map_check(game, map_path))
		destroy_game(game);
	set_game(game, map_path);
	game->win.win = mlx_new_window(game->win.mlx, game->w, game->h, str);
	if (!game->win.win)
		ft_printf("MLX ERROR !\n");
	load_n_put(game);
	count_moves(game, game->moves);
}

int	load_n_put(t_game *game)
{
	t_point	p;

	p.y = 0;
	while ((p.y * SIZE) < game->h)
	{
		p.x = 0;
		while ((p.x * SIZE) < game->w)
		{
			mlx_put_image_to_window(game->win.mlx, game->win.win,
				load_sprites(p, game, game->xpm_ptr),
				(p.x * SIZE), (p.y * SIZE));
			p.x++;
		}
		p.y++;
	}
	if (!game->sta_pl.frames || !game->walk_pl.frames
		|| !game->good_tk.frames)
		return (1);
	else
		return (0);
}

void	*load_sprites(t_point p, t_game *game, void **xpm_ptr)
{
	if (game->map.map[p.y][p.x] == EMPTY)
		return (xpm_ptr[11]);
	else if (game->map.map[p.y][p.x] == WALL)
		return (xpm_ptr[10]);
	else if (game->map.map[p.y][p.x] == BAD)
		return (set_token(game, BAD));
	else if (game->map.map[p.y][p.x] == EXIT)
	{
		game->map.exit = (t_point){p.x, p.y};
		if (game->map.tk_cc == game->map.t_tk)
			return (xpm_ptr[13]);
		else
			return (xpm_ptr[12]);
	}
	else if (game->map.map[p.y][p.x] == TOKEN)
		return (set_token(game, TOKEN));
	else if (game->map.map[p.y][p.x] == PLAYER)
		return (set_player(game, p));
	else
		return (ft_printf("Sprite Error !\n"), NULL);
}
