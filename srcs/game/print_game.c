/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:44:31 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/10 13:49:47 by ccheyrou         ###   ########.fr       */
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

/*void	move(t_cub3d *cub3d)
{
	char	tmp;
	
	// faire le plus petit entier de pos_x et savoir dans quelle case il se trouve 
	// au lieu d'utiliser map_x
	
	if (cub3d->move == 1 && cub3d->map.map[cub3d->ray.map_x - 1][cub3d->ray.map_y] != '1')
	{
		tmp = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x ][cub3d->ray.map_y] = cub3d->map.map[cub3d->ray.map_x - 1][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x - 1][cub3d->ray.map_y] = tmp; 
		cub3d->ray.map_x -= 1;
		// cub3d->ray.pos_x -= 1;
	}
	if (cub3d->move == 2 && cub3d->map.map[cub3d->ray.map_x + 1][cub3d->ray.map_y] != '1')
	{
		tmp = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x ][cub3d->ray.map_y] = cub3d->map.map[cub3d->ray.map_x + 1][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x + 1][cub3d->ray.map_y] = tmp; 
		cub3d->ray.map_x += 1;
		// cub3d->ray.pos_x += 1;
	}
	if (cub3d->move == 3 && cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y - 1] != '1')
	{
		tmp = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x ][cub3d->ray.map_y] = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y - 1];
		cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y - 1] = tmp; 
		cub3d->ray.map_y -= 1;
		// cub3d->ray.pos_y -= 1;
	}
	if (cub3d->move == 4 && cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y + 1] != '1')
	{
		tmp = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x ][cub3d->ray.map_y] = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y + 1];
		cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y + 1] = tmp; 
		cub3d->ray.map_y += 1;
		// cub3d->ray.pos_y += 1;
	}
}*/

void swap_img(t_cub3d *cub3d)
{
	void *tmp;

	tmp = cub3d->img.mlx_img;
	cub3d->img.mlx_img = cub3d->img.mlx_img2;
	cub3d->img.mlx_img2 = tmp;
	tmp = cub3d->img.addr;
	cub3d->img.addr = cub3d->img.addr2;
	cub3d->img.addr2 = tmp;
}

int	print_map(t_cub3d *cub3d)
{
	/*int	x;
	int	y;

	x = 0;*/
	//move(cub3d);
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
	int	j;
	int	i;

	j = 0;
	move_forward_backward(&cub3d->map, &cub3d->ray, cub3d);
	move_left_right(&cub3d->map, &cub3d->ray, cub3d);
	rot_left_right(&cub3d->ray, cub3d);
	while (j < cub3d->screen_height / 2)
	{
		i = -1;
		while (++i < cub3d->screen_width)
			cub3d->img.addr[j * cub3d->img.line_len / 4 + i] = cub3d->img.cell;
		j++;
	}
	while (j < cub3d->screen_height)
	{
		i = -1;
		while (++i < cub3d->screen_width)
			cub3d->img.addr[j * cub3d->img.line_len / 4 + i] = cub3d->img.floor;
		j++;
	}
	ray_pos(cub3d);
	swap_img(cub3d);
	return (0);
}
