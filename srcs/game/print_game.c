/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:44:31 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/20 12:45:41 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image(t_cub3d *cub3d, int *tab, int j, int i)
{
	int		pixel_index;
	int		x;
	int		y;

	y = 0;
	cub3d->img.mlx_img = mlx_new_image(cub3d->game.mlx, 32, 32);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.mlx_img, \
		&cub3d->img.bpp, &cub3d->img.line_len, &cub3d->img.endian);
	while (y < 30)
	{
		x = 0;
		while (x < 30)
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
		cub3d->img.mlx_img, i * 32, j * 32);
}

void	init_player(t_cub3d *cub3d, int *tab, int j, int i)
{
	int		pixel_index;
	int		x;
	int		y;

	y = 12;
	cub3d->img.mlx_img = mlx_new_image(cub3d->game.mlx, 32, 32);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.mlx_img, &cub3d->img.bpp, \
		&cub3d->img.line_len, &cub3d->img.endian);
	while (y < 18)
	{
		x = 12;
		while (x < 18)
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
	cub3d->img.mlx_img, i * 32, j * 32);
}

void	letter_to_image(t_cub3d *cub3d, int x, int y)
{
	const int		wall[3] = {255, 255, 255};
	const int		player[3] = {0, 255, 255};

	if (cub3d->map.map[x][y] == '1')
		init_image(cub3d, wall, x, y);
	else if (cub3d->map.map[x][y] == '0')
		init_image(cub3d, cub3d->map.elem.floor, x, y);
	else if (cub3d->map.map[x][y] == 'N')
		init_player(cub3d, player, x, y);
	else if (cub3d->map.map[x][y] == 'W')
		mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, \
		y * 32, x * 32, 0xF4D03F);
	else if (cub3d->map.map[x][y] == 'S')
		mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, \
		y * 32, x * 32, 0xF4D03F);
	else if (cub3d->map.map[x][y] == 'O')
		mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, \
		y * 32, x * 32, 0xF4D03F);
}

void	print_map(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
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
}
