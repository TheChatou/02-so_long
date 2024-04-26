/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:42:54 by fcoullou          #+#    #+#             */
/*   Updated: 2024/03/25 14:26:17 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	map_borders(t_map *map, t_point s)
{
	t_point	p;

	p.y = 0;
	while (p.y < s.y)
	{
		p.x = 0;
		while (p.x < s.x)
		{
			if ((p.y == 0 || p.y == s.y - 1 || p.x == 0 || p.x == s.x - 1)
				&& (map->map[p.y][p.x] != WALL))
				return (0);
			p.x++;
		}
		p.y++;
	}
	return (1);
}

int	map_read(t_map *map, t_point s)
{
	t_point	p;

	p.y = 0;
	while (p.y < s.y)
	{
		p.x = 0;
		while (p.x < s.x)
		{
			if (map->map[p.y][p.x] == TOKEN)
				map->t_tk++;
			else if (map->map[p.y][p.x] == PLAYER)
				map->pl_cc++;
			else if (map->map[p.y][p.x] == BAD)
				map->t_bad++;
			else if (map->map[p.y][p.x] == EXIT)
				map->exit_cc++;
			p.x++;
		}
		p.y++;
	}
	map->tk_pos = map_tks_pos(map, map->t_tk, TOKEN);
	map->bad_pos = map_tks_pos(map, map->t_bad, BAD);
	if (map->exit_cc != 1 || map->pl_cc != 1 || map->t_tk < 1)
		return (0);
	return (1);
}

t_point	*map_tks_pos(t_map *map, int n, char c)
{
	t_point	*pos_arr;
	t_point	pos;
	int		i;

	pos_arr = (t_point *)ft_calloc(sizeof(t_point), n);
	if (pos_arr == NULL)
		return (NULL);
	i = 0;
	pos.y = 0;
	while (pos.y < map->size.y)
	{
		pos.x = 0;
		while (pos.x < map->size.x)
		{
			if (map->map[pos.y][pos.x] == c)
			{
				pos_arr[i] = pos;
				i++;
			}
			pos.x++;
		}
		pos.y++;
	}
	return (pos_arr);
}

int	map_floodfill(t_map *map, t_point pl)
{
	if (pl.y < 0 || pl.y >= map->size.y || pl.x < 0 || pl.x >= map->size.x)
		return (0);
	if ((map->map[pl.y][pl.x] == '>' || map->map[pl.y][pl.x] == WALL
		|| map->map[pl.y][pl.x] == BAD))
		return (0);
	if (map->map[pl.y][pl.x] == TOKEN)
		map->tk_cc++;
	if ((map->map[pl.y][pl.x] == EXIT || map->valid == 1)
		&& (map->tk_cc == map->t_tk))
		return (1);
	if (map->map[pl.y][pl.x] != EXIT)
		map->map[pl.y][pl.x] = '>';
	if (map->map[pl.y][pl.x] == EXIT)
	{
		map->valid = 1;
		return (0);
	}
	if (map_floodfill(map, (t_point){pl.x - 1, pl.y}) ||
		map_floodfill(map, (t_point){pl.x, pl.y - 1}) ||
		map_floodfill(map, (t_point){pl.x + 1, pl.y}) ||
		map_floodfill(map, (t_point){pl.x, pl.y + 1}))
		return (1);
	return (0);
}

int	map_check(t_game *game, char *map_path)
{
	map_cpy(&game->map, map_path);
	find_player(&game->map);
	game->win.w = game->map.size.x;
	game->win.h = game->map.size.y;
	if (game->win.w > 60 || game->win.h > 31)
		return (ft_printf("! Invalid Map !\n"), destroy_game(game), 0);
	if (map_borders(&game->map, game->map.size)
		&& map_read(&game->map, game->map.size)
		&& map_floodfill(&game->map, game->map.pl_pos))
		return (free_map(game->map), 1);
	else
		return (ft_printf("! Invalid Map !\n"), 0);
}
