/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:39:37 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/09 19:30:31 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cam_pos(t_cub3d *cub3d, int x)
{
	cub3d->ray.cam_x = 2.0 * x / (double)cub3d->screen_width - 1;
	cub3d->ray.raydir_x = cub3d->ray.dir_x + cub3d->ray.plan_x * cub3d->ray.cam_x;
	cub3d->ray.raydir_y = cub3d->ray.dir_y + cub3d->ray.plan_y * cub3d->ray.cam_x;

	cub3d->ray.map_x = (int)cub3d->ray.pos_x;
	cub3d->ray.map_y = (int)cub3d->ray.pos_y;
	cub3d->ray.movespeed = 0.1;
	cub3d->ray.rotspeed = 0.033 * 1.8;
}

void	ray_lenght(t_cub3d *cub3d)
{
	if (cub3d->ray.raydir_y == 0)
	{
		cub3d->ray.deltadist_x = 0;
	}
	else
	{
		if (cub3d->ray.raydir_x == 0)
			cub3d->ray.deltadist_x = 1;
		else
			cub3d->ray.deltadist_x = fabs(1 / cub3d->ray.raydir_x);
	}
	if (cub3d->ray.raydir_x == 0)
	{
		cub3d->ray.deltadist_y = 0;
	}
	else
	{
		if (cub3d->ray.raydir_y == 0)
			cub3d->ray.deltadist_y = 1;
		else
			cub3d->ray.deltadist_y = fabs(1 / cub3d->ray.raydir_y);
	}
	cub3d->ray.hit = 0;
	// cub3d->ray.deltadist_x = fabs(1 / cub3d->ray.raydir_x);
	// cub3d->ray.deltadist_y = fabs(1 / cub3d->ray.raydir_y);
	// cub3d->ray.hit = 0;
}

void	ray_dist(t_cub3d *cub3d)
{
	if (cub3d->ray.raydir_x < 0)
		cub3d->ray.sidedist_x = (cub3d->ray.pos_x - (double)cub3d->ray.map_x) * cub3d->ray.deltadist_x;
	else
		cub3d->ray.sidedist_x = (cub3d->ray.map_x + 1.0 - cub3d->ray.pos_x) * cub3d->ray.deltadist_x;
	if (cub3d->ray.raydir_y < 0)
		cub3d->ray.sidedist_y = (cub3d->ray.pos_y - (double)cub3d->ray.map_y) * cub3d->ray.deltadist_y;
	else
		cub3d->ray.sidedist_y = (cub3d->ray.map_y + 1.0 - cub3d->ray.pos_y) * cub3d->ray.deltadist_y;
	if (cub3d->ray.raydir_x < 0)
		cub3d->ray.step_x = -1;
	else
		cub3d->ray.step_x = 1;
	if (cub3d->ray.raydir_y < 0)
		cub3d->ray.step_y = -1;
	else
		cub3d->ray.step_y = 1;
}

void	dda_algo(t_cub3d *cub3d)
{
	while (cub3d->ray.hit == 0) 
	{
		if (cub3d->ray.sidedist_x < cub3d->ray.sidedist_y)
		{ 
			cub3d->ray.sidedist_x += cub3d->ray.deltadist_x ; 
			cub3d->ray.map_x += cub3d->ray.step_x; 
			cub3d->ray.side = 0 ;
		} 
		else if (cub3d->ray.sidedist_x > cub3d->ray.sidedist_y)
		{ 
			cub3d->ray.sidedist_y += cub3d->ray.deltadist_y ; 
			cub3d->ray.map_y += cub3d->ray.step_y; 
			cub3d->ray.side = 1 ; 
		}
		else
		{ 
			cub3d->ray.sidedist_x += cub3d->ray.deltadist_x ; 
			cub3d->ray.map_x += cub3d->ray.step_x; 
			cub3d->ray.sidedist_y += cub3d->ray.deltadist_y ; 
			cub3d->ray.map_y += cub3d->ray.step_y; 
			cub3d->ray.side = 1 ; 
		}
		if (cub3d->map.map[cub3d->ray.map_y][cub3d->ray.map_x] == '1')
			cub3d->ray.hit = 1;
		else if (cub3d->map.map[cub3d->ray.map_y][cub3d->ray.map_x] == 'X')
			cub3d->ray.hit = 1;
	}
}

void	calculate_wall(t_cub3d *cub3d)
{
	if (cub3d->ray.side == 0)
		cub3d->ray.paperwalldist = (cub3d->ray.map_x - cub3d->ray.pos_x + (1 - cub3d->ray.step_x) / 2.0)
			/ cub3d->ray.raydir_x;
	else
		cub3d->ray.paperwalldist = (cub3d->ray.map_y - cub3d->ray.pos_y + (1 - cub3d->ray.step_y) / 2.0)
			/ cub3d->ray.raydir_y;
	cub3d->ray.lineheight = (double)(cub3d->screen_height / cub3d->ray.paperwalldist);	
	cub3d->ray.drawstart = (cub3d->screen_height / 2) - (cub3d->ray.lineheight / 2);
	
	if (cub3d->ray.drawstart < 0)
		cub3d->ray.drawstart = 0 ;

	cub3d->ray.drawend = (cub3d->screen_height / 2) + (cub3d->ray.lineheight / 2); 
	if (cub3d->ray.drawend >= cub3d->screen_height)
		cub3d->ray.drawend = cub3d->screen_height;
}

void	ray_pos(t_cub3d *cub3d)
{
	float	x;
	
	x = 0;
	cub3d->ray.hit = 0;
	cub3d->ray.paperwalldist = 0;
	cub3d->ray.lineheight = 0;

	while (x < cub3d->screen_width)
	{
		cam_pos(cub3d, x);
		ray_lenght(cub3d);
		ray_dist(cub3d);
		dda_algo(cub3d);
		calculate_wall(cub3d);
		draw(cub3d, x, cub3d->ray.drawstart, cub3d->ray.drawend);
		x ++;
	}
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win, cub3d->img.mlx_img, 0, 0);
}