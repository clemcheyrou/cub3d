/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:37:04 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/10 18:07:17 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward_backward(t_map *map, t_ray *ray, t_cub3d *cub3d)
{
	if (cub3d->move == 1)
	{
		if (map->map[(int)(ray->pos_y + ray->dir_y)][(int)ray->pos_x] == '0' ||
		map->map[(int)(ray->pos_y + ray->dir_y * 0.1)][(int)ray->pos_x] != '1')
			ray->pos_y += ray->dir_y * 0.03;
		if (map->map[(int)(ray->pos_y)][(int)(ray->pos_x + ray->dir_x)] == '0'
		|| map->map[(int)(ray->pos_y)][(int)(ray->pos_x + ray->dir_x * 0.1)] \
		!= '1')
			ray->pos_x += ray->dir_x * 0.03;
	}
	if (cub3d->move == 2)
	{
		if (map->map[(int)(ray->pos_y - ray->dir_y)][(int)ray->pos_x] == '0'
		|| map->map[(int)(ray->pos_y - ray->dir_y * 0.1)][(int)ray->pos_x] \
		!= '1')
			ray->pos_y -= ray->dir_y * 0.1;
		if (map->map[(int)(ray->pos_y)][(int)(ray->pos_x - ray->dir_x)] == '0'
		|| map->map[(int)(ray->pos_y)][(int)(ray->pos_x - ray->dir_x * 0.1)] \
		!= '1')
			ray->pos_x -= ray->dir_x * 0.1;
	}
}

void	move_left_right(t_map *map, t_ray *ray, t_cub3d *cub3d)
{
	if (cub3d->move == 3)
	{
		if (map->map[(int)ray->pos_y][(int)(ray->pos_x + ray->dir_y)] == '0' ||
		map->map[(int)ray->pos_y][(int)(ray->pos_x + ray->dir_y * 0.1)] != '1')
			ray->pos_x += ray->dir_y * 0.03;
		if (map->map[(int)(ray->pos_y - ray->dir_x)][(int)ray->pos_x] == '0' ||
		map->map[(int)(ray->pos_y - ray->dir_x * 0.1)][(int)ray->pos_x] != '1')
			ray->pos_y -= ray->dir_x * 0.03;
	}
	if (cub3d->move == 4)
	{
		if (map->map[(int)ray->pos_y][(int)(ray->pos_x - ray->dir_y)] == '0' ||
		map->map[(int)ray->pos_y][(int)(ray->pos_x - ray->dir_y * 0.1)] != '1')
			ray->pos_x -= ray->dir_y * 0.03;
		if (map->map[(int)(ray->pos_y + ray->dir_x)][(int)ray->pos_x] == '0' ||
		map->map[(int)ray->pos_y][(int)(ray->pos_x - ray->dir_y * 0.1)] != '1')
			ray->pos_y += ray->dir_x * 0.03;
	}
}

void	rot_left_right(t_ray *ray, t_cub3d *cub3d)
{
	double	olddir_x;
	double	oldplan_x;

	if (cub3d->move == 6)
	{
		olddir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(0.02) - ray->dir_y * sin(0.02);
		ray->dir_y = olddir_x * sin(0.02) + ray->dir_y * cos(0.02);
		oldplan_x = ray->plan_x;
		ray->plan_x = ray->plan_x * cos(0.02) - ray->plan_y * sin(0.02);
		ray->plan_y = oldplan_x * sin(0.02) + ray->plan_y * cos(0.02);
	}
	if (cub3d->move == 5)
	{
		olddir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(-0.02) - ray->dir_y * sin(-0.02);
		ray->dir_y = olddir_x * sin(-0.02) + ray->dir_y * cos (-0.02);
		oldplan_x = ray->plan_x;
		ray->plan_x = ray->plan_x * cos(-0.02) - ray->plan_y * sin(-0.02);
		ray->plan_y = oldplan_x * sin(-0.02) + ray->plan_y * cos(-0.02);
	}
}

int	move_player(int keycode, t_cub3d *cub3d)
{
	if (keycode == W_K)
		cub3d->move = 1;
	if (keycode == S_K)
		cub3d->move = 2;
	if (keycode == A_K)
		cub3d->move = 3;
	if (keycode == D_K)
		cub3d->move = 4;
	if (keycode == LEFT_A)
		cub3d->move = 5;
	if (keycode == RIGHT_A)
		cub3d->move = 6;
	if (keycode == ESC_K)
		free_before_exit(cub3d, 1);
	return (1);
}

int	release_player(int keycode, t_cub3d *cub3d)
{
	if (keycode == W_K || keycode == A_K || keycode == S_K || keycode == D_K
		|| keycode == LEFT_A || keycode == RIGHT_A)
		cub3d->move = 0;
	return (1);
}
