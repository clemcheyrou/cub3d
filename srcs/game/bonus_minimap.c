/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:26:26 by adegain           #+#    #+#             */
/*   Updated: 2023/04/10 19:46:01 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_miniwalls(t_cub3d *cub3d, int y, int x)
{
	int	j;
	int	i;

	j = -1;
	if (cub3d->map.map[y][x] == '1')
	{
		while (++j < 10)
		{
			i = -1;
			while (++i < 10)
			{
				cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4 + (x * 10)] \
				= cub3d->img.floor;
				cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4 + (x * \
				10)] = cub3d->img.floor;
				cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4 + (x * \
				10 + i)] = cub3d->img.floor;
				cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4 + (x * 10 \
				+ i)] = cub3d->img.floor;
			}
		}
	}
}

void	print_minifloor(t_cub3d *cub3d, int y, int x)
{
	int	j;
	int	i;

	j = -1;
	if (cub3d->map.map[y][x] == '0')
	{
		while (++j < 10)
		{
			i = -1;
			while (++i < 10)
			{
				cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4 + (x * \
				10)] = cub3d->img.cell;
				cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4 + (x * \
				10)] = cub3d->img.cell;
				cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4 + (x * \
				10 + i)] = cub3d->img.cell;
				cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4 + (x * 10 \
				+ i)] = cub3d->img.cell;
			}
		}
	}
}

void	print_miniplayer(t_cub3d *cub3d, int y, int x)
{
	int	j;
	int	i;

	j = -1;
	if (y == (int)cub3d->ray.pos_y && x == (int)cub3d->ray.pos_x)
	{
		while (++j < 10)
		{
			i = -1;
			while (++i < 10)
			{
				cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4 + (x * \
				10)] = 0xFF69B4;
				cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4 + (x * \
				10)] = 0xFF69B4;
				cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4 + (x * \
				10 + i)] = 0xFF69B4;
				cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4 + (x * 10 \
				+ i)] = 0xFF69B4;
			}
		}
	}
}

void	letter_to_image(t_cub3d *cub3d, int y, int x)
{
	print_miniwalls(cub3d, y, x);
	print_minifloor(cub3d, y, x);
	print_miniplayer(cub3d, y, x);
}
