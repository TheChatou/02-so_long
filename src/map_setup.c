/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:28:22 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/26 17:03:44 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	map_cpy(t_map *map, char *map_path)
{
	int		fd;
	int		i;
	char	*line;

	map->size.y = count_lines(map_path);
	map->map = ft_calloc(map->size.y, sizeof(char *));
	if (!map->map)
	{
		ft_printf("Erreur lors de l'allocation de mémoire pour map->map");
		exit(EXIT_FAILURE);
	}
	fd = open(map_path, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->map[i] = ft_strdup(line);
		map->size.x = ft_strlen(map->map[i]);
		i++;
		free(line);
	}
	close(fd);
}

int	count_lines(char *path)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(path, O_RDONLY);
	rows = 0;
	if (fd == -1)
	{
		ft_printf("Erreur lors de l'ouverture du fichier\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		rows++;
		free(line);
	}
	close(fd);
	return (rows);
}

void	count_t_tk(t_map *map)
{
	t_point	p;

	map->t_tk = 0;
	p.y = 0;
	while (p.y < map->size.y)
	{
		p.x = 0;
		while (p.x < map->size.x)
		{
			if (map->map[p.y][p.x] == TOKEN)
				map->t_tk += 1;
			p.x++;
		}
		p.y++;
	}
}

void	find_player(t_map *map)
{
	t_point	p;

	p.y = 0;
	while (p.y < map->size.y)
	{
		p.x = 0;
		while (p.x < map->size.x)
		{
			if (map->map[p.y][p.x] == 0)
				break ;
			if (map->map[p.y][p.x] == PLAYER)
				map->pl_pos = p;
			p.x++;
		}
		p.y++;
	}
}
