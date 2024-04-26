/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:46:52 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/02 14:36:57 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	keys_moves(int keysym, t_game *game)
{
	int	res;

	res = EXIT_SUCCESS;
	game->dir = keysym;
	if (!game->win.win)
		return (EXIT_FAILURE);
	if (keysym == KEY_A || keysym == LEFT)
		res += move_player(game, (t_point){-1, 0}, &game->map);
	else if (keysym == KEY_D || keysym == RIGHT)
		res += move_player(game, (t_point){1, 0}, &game->map);
	else if (keysym == KEY_W || keysym == UP)
		res += move_player(game, (t_point){0, -1}, &game->map);
	else if (keysym == KEY_S || keysym == DOWN)
		res += move_player(game, (t_point){0, 1}, &game->map);
	else if (keysym == ESC || keysym == KEY_Q)
		destroy_game(game);
	if (res > 0)
		return (destroy_game(game), EXIT_FAILURE);
	if (game->map.t_tk == game->map.tk_cc)
		mlx_put_image_to_window(game->win.mlx, game->win.win,
			game->xpm_ptr[13], game->map.exit.x * SIZE,
			game->map.exit.y * SIZE);
	return (EXIT_SUCCESS);
}

int	move_player(t_game *game, t_point mv, t_map *map)
{
	int	x;
	int	y;

	x = map->pl_pos.x;
	y = map->pl_pos.y;
	if (map->map[y + mv.y][x + mv.x] == EXIT && map->t_tk == map->tk_cc)
		return (you_win(), destroy_game(game), EXIT_SUCCESS);
	if (map->map[y + mv.y][x + mv.x] == BAD)
		return (game_over(), destroy_game(game), EXIT_FAILURE);
	else if (map->map[y + mv.y][x + mv.x] == WALL
		|| map->map[y + mv.y][x + mv.x] == EXIT)
		return (0);
	else if (map->map[y + mv.y][x + mv.x] == TOKEN)
	{
		map->tk_cc += 1;
		return (up_load_free(game, mv), 0);
	}
	return (up_load_free(game, mv), 0);
}

void	count_moves(t_game *game, int moves)
{
	int			digit;
	static int	tab = 0;

	if (moves >= 10)
		count_moves(game, moves / 10);
	digit = moves % 10;
	if (moves >= 1000)
		tab = 3;
	else if (moves >= 100)
		tab = 2;
	else if (moves >= 10)
		tab = 1;
	else
		tab = 0;
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		game->xpm_ptr[digit], (((game->win.w / 2) + tab) * SIZE), (0 * SIZE));
}

void	up_load_free(t_game *game, t_point mv)
{
	update_pos(game, &game->map, (t_point){mv.x, mv.y});
	game->moves++;
	count_moves(game, game->moves);
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		load_sprites(game->map.pl_pos, game, game->xpm_ptr),
		(game->map.pl_pos.x * SIZE), (game->map.pl_pos.y * SIZE));
	free_lst_anim(&game->sta_pl.frames, game->win.mlx);
}

void	update_pos(t_game *game, t_map *map, t_point mv)
{
	map->map[map->pl_pos.y][map->pl_pos.x] = ' ';
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		load_sprites(map->pl_pos, game, game->xpm_ptr),
		(map->pl_pos.x * SIZE), (map->pl_pos.y * SIZE));
	map->pl_pos.x += mv.x;
	map->pl_pos.y += mv.y;
	map->map[map->pl_pos.y][map->pl_pos.x] = PLAYER;
}
