/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:37:04 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/03 13:37:31 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player(int keycode, t_cub3d *cub3d)
{
	if (keycode == W_K)
		cub3d->move = 1;
	else if (keycode == A_K)
		cub3d->move = 2;
	else if (keycode == S_K)
		cub3d->move = 3;
	else if (keycode == D_K)
		cub3d->move = 4;
	if (keycode == LEFT_A)
		cub3d->ray.cam_x += 0.1;
	else if (keycode == RIGHT_A)
		cub3d->ray.cam_x -= 0.1;
	else if (keycode == ESC_K)
		free_before_exit(cub3d);
	return (1);
}

int	release_player(int keycode, t_cub3d *cub3d)
{
	if (keycode == W_K)
		cub3d->move = 0;
	else if (keycode == A_K)
		cub3d->move = 0;
	else if (keycode == S_K)
		cub3d->move = 0;
	else if (keycode == D_K)
		cub3d->move = 0;
	return (1);
}
