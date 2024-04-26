/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:29:18 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/02 17:00:09 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	main(int argc, char **argv)
{
	char	*map_path;
	t_game	game;

	if (argc == 1)
		return (ft_printf("No argument !"), EXIT_FAILURE);
	else if (argc != 2)
		return (ft_printf("Too many arguments !"), EXIT_FAILURE);
	map_path = argv[1];
	init_game(&game);
	game_launch(&game, map_path, "Felix the 'Pac' Cat");
	mlx_loop_hook(game.win.mlx, &update, &game);
	mlx_hook(game.win.win, KeyPress, KeyPressMask, &keys_moves, &game);
	mlx_hook(game.win.win, DestroyNotify, NoEventMask, &destroy_game, &game);
	mlx_loop(game.win.mlx);
	return (0);
}
