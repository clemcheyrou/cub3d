/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:44:31 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/10 18:14:44 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap_img(t_cub3d *cub3d)
{
	void	*tmp;

	tmp = cub3d->img.mlx_img;
	cub3d->img.mlx_img = cub3d->img.mlx_img2;
	cub3d->img.mlx_img2 = tmp;
	tmp = cub3d->img.addr;
	cub3d->img.addr = cub3d->img.addr2;
	cub3d->img.addr2 = tmp;
}

void	print_background(t_cub3d *cub3d)
{
	int	j;
	int	i;

	j = 0;
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
			cub3d->img.addr[j * cub3d->img.line_len / 4 + i] = \
			cub3d->img.floor;
		j++;
	}
}

void	letter_to_image(t_cub3d *cub3d, int y, int x)
{
	int j;
	int i;

	j = 0;
	if (cub3d->map.map[y][x] == '1')
	{
		while (j < 10)
		{
			i = 0;
			while (i < 10)
			{
				cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4 + (x * 10)] = cub3d->img.floor;
				cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4 + (x * 10)] = cub3d->img.floor;
				cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4 + (x * 10 + i)] = cub3d->img.floor;
				cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4 + (x * 10 + i)] = cub3d->img.floor;
				i++;
			}
			j++;
		}
	}
	j = 0;
	if (cub3d->map.map[y][x] == '0')
	{
		while (j < 10)
		{
			i = 0;
			while (i < 10)
			{
				cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4 + (x * 10)] = cub3d->img.cell;
				cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4 + (x * 10)] = cub3d->img.cell;
				cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4 + (x * 10 + i)] = cub3d->img.cell;
				cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4 + (x * 10 + i)] = cub3d->img.cell;
				i++;
			}
			j++;
		}
	}
	j = 0;
	if (y == (int)cub3d->ray.pos_y && x == (int)cub3d->ray.pos_x)
	{
		while (j < 10)
		{
			i = 0;
			while (i < 10)
			{
				cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4 + (x * 10)] = 0xFF69B4;
				cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4 + (x * 10)] = 0xFF69B4;
				cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4 + (x * 10 + i)] = 0xFF69B4;
				cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4 + (x * 10 + i)] = 0xFF69B4;
				i++;
			}
			j++;
		}
	}
}

int	print_map(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	move_forward_backward(&cub3d->map, &cub3d->ray, cub3d);
	move_left_right(&cub3d->map, &cub3d->ray, cub3d);
	rot_left_right(&cub3d->ray, cub3d);
	print_background(cub3d);
	ray_pos(cub3d);
	swap_img(cub3d);
	while (cub3d->map.map[y])
	{
		x = 0;
		while (cub3d->map.map[y][x])
		{
			letter_to_image(cub3d, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win, \
		cub3d->img.mlx_img, 0, 0);
	return (0);
}
