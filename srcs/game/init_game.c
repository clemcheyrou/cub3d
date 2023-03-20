/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:09:18 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/20 12:46:20 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move(t_cub3d *cub3d)
{
	(void)cub3d;
	return (1);
}

int	move_player(int keycode, t_cub3d *cub3d)
{
	if (keycode == 'W' || keycode == 'w')
		move(cub3d);
	else if (keycode == 'A' || keycode == 'a')
		move(cub3d);
	else if (keycode == 'S' || keycode == 's')
		move(cub3d);
	else if (keycode == 'D' || keycode == 'd')
		move(cub3d);
	else if (keycode == 65307)
		free_before_exit(cub3d);
	return (0);
}

int	game(t_cub3d *cub3d)
{
	cub3d->game.mlx = mlx_init();
	if (!cub3d->game.mlx)
		return (0);
	cub3d->rx = 800;
	cub3d->ry = 600;
	mlx_get_screen_size(cub3d->game.mlx, &cub3d->sizex, &cub3d->sizey);
	if (cub3d->rx > cub3d->sizex)
		cub3d->rx = cub3d->sizex;
	if (cub3d->ry > cub3d->sizey)
		cub3d->ry = cub3d->sizey;
	cub3d->game.win = mlx_new_window(cub3d->game.mlx, cub3d->rx * 2, \
		cub3d->ry * 2, CHAR_TITLE);
	if (!cub3d->game.win)
		return (0);
	print_map(cub3d);
	mlx_loop(cub3d->game.mlx);
	mlx_key_hook(cub3d->game.win, move_player, &cub3d);
	mlx_hook(cub3d->game.win, 33, 1L << 2, close_btn, &cub3d);
	return (1);
}
