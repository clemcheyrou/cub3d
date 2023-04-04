/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:44:31 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/04 16:04:14 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	letter_to_image(t_cub3d *cub3d, int x, int y)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (cub3d->map.map[x][y] == '1') 
	{
		while(i <= 10)
		{
			j = 0;
			while(j <= 10)
			{
    			mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, x, y, 0x000000);
				j++;
			}
			i++;
		}
    }
    else
	{
        mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, i, j, 0xCCCCCC); // Gris pour les espaces vides
    }
}*/

void	swap(t_cub3d *cub3d)
{
	char	tmp;
	
	if (cub3d->move == 1 && cub3d->map.map[cub3d->ray.map_x - 1][cub3d->ray.map_y] != '1')
	{
		tmp = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x ][cub3d->ray.map_y] = cub3d->map.map[cub3d->ray.map_x - 1][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x - 1][cub3d->ray.map_y] = tmp; 
		cub3d->ray.map_x -= 1;
		cub3d->ray.pos_x -= 1;
	}
	if (cub3d->move == 2 && cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y - 1] != '1')
	{
		tmp = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x ][cub3d->ray.map_y] = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y - 1];
		cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y - 1] = tmp; 
		cub3d->ray.map_y -= 1;
		cub3d->ray.pos_y -= 1;
	}
	if (cub3d->move == 3 && cub3d->map.map[cub3d->ray.map_x + 1][cub3d->ray.map_y] != '1')
	{
		tmp = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x ][cub3d->ray.map_y] = cub3d->map.map[cub3d->ray.map_x + 1][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x + 1][cub3d->ray.map_y] = tmp; 
		cub3d->ray.map_x += 1;
		cub3d->ray.pos_x += 1;
	}
	if (cub3d->move == 4 && cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y + 1] != '1')
	{
		tmp = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x ][cub3d->ray.map_y] = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y + 1];
		cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y + 1] = tmp; 
		cub3d->ray.map_y += 1;
		cub3d->ray.pos_y += 1;
	}
}

int	print_map(t_cub3d *cub3d)
{
	/*int	x;
	int	y;

	x = 0;*/
	swap(cub3d);
	def_ray(cub3d);
	ray_pos(cub3d);
	/*while (cub3d->map.map[x])
	{
		y = 0;
		while (cub3d->map.map[x][y])
		{
			letter_to_image(cub3d, x, y);
			y++;
		}
		x++;
	}*/
	return (0);
}
