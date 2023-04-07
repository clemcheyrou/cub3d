/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:41:00 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/07 17:54:31 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	strcmp_int(int nb1, int nb2)
{
	if (nb1 == nb2)
		return (1);
	return (0);
}

typedef struct s_dir
{
	int		idx;
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
}	t_dir;

void	def_direction(t_cub3d *cub3d)
{
	int			i;
	const t_dir	storage [4] = {
	{0, -1, 0, 0, 0.66},
	{1, 1, 0, 0, -0.66},
	{2, 0, 1, 0.66, 0},
	{3, 0, -1, -0.66, 0}
	};

	i = 0;
	while (i < 4)
	{
		if (strcmp_int(cub3d->map.direction, storage[i].idx))
		{
			cub3d->ray.dir_x = storage[i].dir_x;
			cub3d->ray.dir_y = storage[i].dir_y;
			cub3d->ray.plan_x = storage[i].plan_x;
			cub3d->ray.plan_y = storage[i].plan_y;
			return ;
		}
		i++;
	}
}

void	def_ray(t_cub3d *cub3d)
{
	cub3d->screen_width = 800;
	cub3d->screen_height = 600;
	cub3d->left_key = 0;
	cub3d->right_key = 0;
	cub3d->move = 0;
	cub3d->ray.pos_x = (double)cub3d->map.x + 0.5;
	cub3d->ray.pos_y = (double)cub3d->map.y + 0.5;
	def_direction(cub3d);
}
