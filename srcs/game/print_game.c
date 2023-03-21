/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:44:31 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/21 16:01:33 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image(t_cub3d *cub3d, int *tab, int j, int i)
{
	int		pixel_index;
	int		x;
	int		y;

	y = 0;
	cub3d->img.mlx_img = mlx_new_image(cub3d->game.mlx, 10, 10);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.mlx_img, \
		&cub3d->img.bpp, &cub3d->img.line_len, &cub3d->img.endian);
	while (y < 30)
	{
		x = 0;
		while (x < 30)
		{
			pixel_index = (y * cub3d->img.line_len) + \
			( x * (cub3d->img.bpp / 8));
			cub3d->img.addr[pixel_index] = tab[0];
			cub3d->img.addr[pixel_index + 1] = tab[1];
			cub3d->img.addr[pixel_index + 2] = tab[2];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win, \
		cub3d->img.mlx_img, i * 10, j * 10);
}

void	init_player(t_cub3d *cub3d, int *tab, int j, int i)
{
	int		pixel_index;
	int		x;
	int		y;

	y = 0;
	cub3d->img.mlx_img = mlx_new_image(cub3d->game.mlx, 4, 4);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.mlx_img, &cub3d->img.bpp, \
		&cub3d->img.line_len, &cub3d->img.endian);
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			pixel_index = (y * cub3d->img.line_len) + \
			(x * (cub3d->img.bpp / 8));
			cub3d->img.addr[pixel_index] = tab[0];
			cub3d->img.addr[pixel_index + 1] = tab[1];
			cub3d->img.addr[pixel_index + 2] = tab[2];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win, \
	cub3d->img.mlx_img, i * 10, j * 10);
}

void	letter_to_image(t_cub3d *cub3d, int x, int y)
{
	int		wall[3] = {255, 255, 255};
	int		player[3] = {0, 255, 255};

	if (cub3d->map.map[x][y] == '1')
		init_image(cub3d, wall, x, y);
	else if (cub3d->map.map[x][y] == '0')
		init_image(cub3d, cub3d->map.elem.floor, x, y);
	else if (cub3d->map.map[x][y] == 'N')
		init_player(cub3d, player, x, y);
}

void	swap(t_cub3d *cub3d)
{
	char	tmp;
	
	if (cub3d->move == 1 && cub3d->map.map[cub3d->ray.map_x - 1][cub3d->ray.map_y] != '1')
	{
		tmp = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x ][cub3d->ray.map_y] = cub3d->map.map[cub3d->ray.map_x - 1][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x - 1][cub3d->ray.map_y] = tmp; 
		cub3d->ray.map_x -= 1;
	}
	if (cub3d->move == 2 && cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y - 1] != '1')
	{
		tmp = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x ][cub3d->ray.map_y] = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y - 1];
		cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y - 1] = tmp; 
		cub3d->ray.map_y -= 1;
	}
	if (cub3d->move == 3 && cub3d->map.map[cub3d->ray.map_x + 1][cub3d->ray.map_y] != '1')
	{
		tmp = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x ][cub3d->ray.map_y] = cub3d->map.map[cub3d->ray.map_x + 1][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x + 1][cub3d->ray.map_y] = tmp; 
		cub3d->ray.map_x += 1;
	}
	if (cub3d->move == 4 && cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y + 1] != '1')
	{
		tmp = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y];
		cub3d->map.map[cub3d->ray.map_x ][cub3d->ray.map_y] = cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y + 1];
		cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y + 1] = tmp; 
		cub3d->ray.map_y += 1;
	}
}

int	print_map(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	swap(cub3d);
	while (cub3d->map.map[x])
	{
		y = 0;
		while (cub3d->map.map[x][y])
		{
			letter_to_image(cub3d, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
