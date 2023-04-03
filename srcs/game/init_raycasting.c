/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:41:00 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/03 13:41:13 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	def_ray(t_cub3d *cub3d)
{
	cub3d->screen_width = 800;
	cub3d->screen_height = 600;
	cub3d->left_key = 0;
	cub3d->right_key = 0;
	cub3d->move = 0;
	if (cub3d->map.direction == 0)
	{
		cub3d->ray.dir_x = -1;
		cub3d->ray.dir_y = 0;
		cub3d->ray.plan_x = 0;
		cub3d->ray.plan_y = 0.66;
	}
}