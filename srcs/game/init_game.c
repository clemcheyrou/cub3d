/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:09:18 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/16 19:27:20 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	letter_to_image(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->map.map[x][y] == '1')
	{
		mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, y *  cub3d->map.map_length, x * 32, 0xFFFFFF);	
	}	
	else if (cub3d->map.map[x][y] == '0')
		mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, y *  cub3d->map.map_length, x * 32, 0xFFFFFF);
	else if (cub3d->map.map[x][y] == 'N')
		mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, y * 32, x * 32, 0xF4D03F);
	else if (cub3d->map.map[x][y] == 'W')
		mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, y * 32, x * 32, 0xF4D03F);
	else if (cub3d->map.map[x][y] == 'S')		
		mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, y * 32, x * 32, 0xF4D03F);
	else if (cub3d->map.map[x][y] == 'O')		
		mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, y * 32, x * 32, 0xF4D03F);
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

void	init_image(t_cub3d *cub3d)
{
	char    *pixel;
	int		i;

	i = 0;
	
	cub3d->img.bpp = 32;
	cub3d->img.line_len = 32 * cub3d->map.map_length;
	cub3d->img.endian = 1;
	cub3d->img.mlx_img = mlx_new_image(cub3d->game.mlx, cub3d->map.map_length, cub3d->map.map_height);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.mlx_img, &cub3d->img.bpp, &cub3d->img.line_len, &cub3d->img.endian);
	pixel = cub3d->img.addr + (0 * cub3d->img.line_len + 1 * (cub3d->img.bpp / 8));
	while (i >= 0)
	{
		if (cub3d->img.endian != 0)
			*pixel++ = (0xFF00 >> i) & 0xFF;
		else
			*pixel++ = (0xFF00 >> (cub3d->img.bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
	pixel = cub3d->img.addr + (0 * cub3d->img.line_len + 2 * (cub3d->img.bpp / 8));
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win, cub3d->img.mlx_img, 0, 0);
}


int	game(t_cub3d *cub3d)
{
	
	cub3d->game.mlx = mlx_init();
	if (!cub3d->game.mlx)
		return (0); //free
	cub3d->game.win = mlx_new_window(cub3d->game.mlx, cub3d->map.map_length * 32, \
		cub3d->map.map_height * 32, CHAR_TITLE);
	if (!cub3d->game.win)
	{
		free(cub3d->game.win);
		return (0);
	}
	init_image(cub3d);
	print_map(cub3d);
	mlx_loop(cub3d->game.mlx);
	mlx_destroy_display(cub3d->game.mlx);
	free(cub3d->game.mlx);
	return (1);
}
