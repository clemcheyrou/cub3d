/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:39:37 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/11 13:53:41 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cam_pos(t_ray *ray, int screen_width, int x)
{
	ray->cam_x = 2.0 * x / (double)screen_width - 1;
	ray->raydir_x = ray->dir_x + ray->plan_x * ray->cam_x;
	ray->raydir_y = ray->dir_y + ray->plan_y * ray->cam_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
}

void	ray_dist(t_ray *ray)
{
	if (ray->raydir_x < 0)
		ray->sidedist_x = (ray->pos_x - ray->map_x) * ray->deltadist_x;
	else
		ray->sidedist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->deltadist_x;
	if (ray->raydir_y < 0)
		ray->sidedist_y = (ray->pos_y - ray->map_y) * ray->deltadist_y;
	else
		ray->sidedist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->deltadist_y;
	if (ray->raydir_x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->raydir_y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}

void	dda_algo(t_ray *ray, t_map *map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0 ;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1 ;
		}
		if (map->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
		else if (map->map[ray->map_y][ray->map_x] == 'X')
			ray->hit = 1;
	}
}

void	wall_lenght(t_ray *ray, int screen_height)
{
	if (ray->side == 0)
		ray->paperwalldist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->paperwalldist = (ray->sidedist_y - ray->deltadist_y);
	if (ray->paperwalldist == 0)
		ray->paperwalldist = 0.01;
	ray->lineheight = (double)(screen_height / ray->paperwalldist);
	ray->drawstart = (screen_height / 2) - (ray->lineheight / 2);
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = (screen_height / 2) + (ray->lineheight / 2);
	if (ray->drawend >= screen_height)
		ray->drawend = screen_height;
}

void	ray_pos(t_cub3d *cub3d)
{
	int	x;

	x = 0;
	while (x < cub3d->screen_width)
	{
		cam_pos(&cub3d->ray, cub3d->screen_width, x);
		ray_dist(&cub3d->ray);
		dda_algo(&cub3d->ray, &cub3d->map);
		wall_lenght(&cub3d->ray, cub3d->screen_height);
		draw_wall(cub3d, x, &cub3d->ray, &cub3d->text);
		x ++;
	}
}
