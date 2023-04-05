/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:37:04 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/05 18:50:00 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward_backward(t_map *map, t_ray *ray, t_cub3d *cub3d)
{
	if (cub3d->move == 1)
	{
		printf("OH\n");
		if (map->map[(int)(ray->pos_x + (ray->dir_x * ray->movespeed * 2))][(int)ray->pos_y] == '0')
			ray->pos_x += ray->dir_x * ray->movespeed;
		if (map->map[(int)(ray->pos_x)][(int)(ray->pos_y + (ray->dir_y * ray->movespeed * 2))] == '0')
			ray->pos_y += ray->dir_y * ray->movespeed;
	}
	if (cub3d->move == 2)
	{
		if (map->map[(int)(ray->pos_x - (ray->dir_x * ray->movespeed * 2))][(int)ray->pos_y] == '0')
			ray->pos_x -= ray->dir_x * ray->movespeed;
		if (map->map[(int)(ray->pos_x)][(int)(ray->pos_y - (ray->dir_y * ray->movespeed * 2))] == '0')
			ray->pos_y -= ray->dir_y * ray->movespeed;
	}
}

void	move_left_right(t_map *map, t_ray *ray, t_cub3d *cub3d)
{
	if (cub3d->move == 3)
	{
		if (map->map[(int)(ray->pos_x - ray->dir_y * (ray->movespeed * 2))][(int)ray->pos_y] == '0')
			ray->pos_x -= ray->dir_y * ray->movespeed;
		if (map->map[(int)ray->pos_x][(int)(ray->pos_y - ray->dir_x * (ray->movespeed * 2))] == '0')
			ray->pos_y += ray->dir_x * ray->movespeed;
	}
	if (cub3d->move == 4)
	{
		if (map->map[(int)(ray->pos_x + ray->dir_y * (ray->movespeed * 2))][(int)ray->pos_y] == '0')
			ray->pos_x += ray->dir_y * ray->movespeed;
		if (map->map[(int)ray->pos_x][(int)(ray->pos_y + ray->dir_x * (ray->movespeed * 2))] == '0')
			ray->pos_y -= ray->dir_x * ray->movespeed;
	}
}

void	change_position(t_cub3d *cub3d)
{
	if (cub3d->ray.dir_x == -1 && cub3d->ray.dir_y == 0)
		cub3d->map.direction = 0;
	if (cub3d->ray.dir_x == 1 && cub3d->ray.dir_y == 0)
		cub3d->map.direction = 1;
	if (cub3d->ray.dir_x == 0 && cub3d->ray.dir_y == -1)
		cub3d->map.direction = 2;
	if (cub3d->ray.dir_x == 0 && cub3d->ray.dir_y == 1)
		cub3d->map.direction = 3;
}

void	rot_left_right(t_ray *ray, t_cub3d *cub3d)
{
	double	olddir_x;
	double	oldplan_x;

	olddir_x = ray->dir_x;
	oldplan_x = ray->plan_x;
	if (cub3d->move == 5)
	{
		ray->dir_x = ray->dir_x * cos(ray->rotspeed / 2) - ray->dir_y * sin(ray->rotspeed / 2);
		ray->dir_y = olddir_x * sin(ray->rotspeed / 2) + ray->dir_y * cos(ray->rotspeed / 2);
		ray->plan_x = ray->plan_x * cos(ray->rotspeed / 2) - ray->plan_y * sin(ray->rotspeed / 2);
		ray->plan_y = oldplan_x * sin(ray->rotspeed / 2) + ray->plan_y * cos(ray->rotspeed / 2);
		change_position(cub3d);
	}
	if (cub3d->move == 6)
	{
		ray->dir_x = ray->dir_x * cos(-ray->rotspeed / 2) - ray->dir_y * sin(-ray->rotspeed / 2);
		ray->dir_y = olddir_x * sin(-ray->rotspeed / 2) + ray->dir_y * cos (-ray->rotspeed / 2);
		ray->plan_x = ray->plan_x * cos(-ray->rotspeed / 2) - ray->plan_y * sin(-ray->rotspeed / 2);
		ray->plan_y = oldplan_x * sin(-ray->rotspeed / 2) + ray->plan_y * cos(-ray->rotspeed / 2);
		change_position(cub3d);
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
