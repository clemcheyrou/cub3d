/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:26:26 by adegain           #+#    #+#             */
/*   Updated: 2023/04/11 12:58:51 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_mini(t_cub3d *cub3d, int y, int x, int color)
{
	int	j;
	int	i;

	j = -1;
	while (++j < 10)
	{
		i = -1;
		while (++i < 10)
		{
			cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4
				+ (x * 10)] = color;
			cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4
				+ (x * 10)] = color;
			cub3d->img.addr[(y * 10 + j) * cub3d->img.line_len / 4
				+ (x * 10 + i)] = color;
			cub3d->img.addr[(y * 10) * cub3d->img.line_len / 4
				+ (x * 10 + i)] = color;
		}
	}
}

void	letter_to_image(t_cub3d *cub3d, int y, int x)
{
	if (cub3d->map.map[y][x] == '1')
		print_mini(cub3d, y, x, cub3d->img.floor);
	if (cub3d->map.map[y][x] == '0')
		print_mini(cub3d, y, x, cub3d->img.cell);
	if (y == (int)cub3d->ray.pos_y && x == (int)cub3d->ray.pos_x)
		print_mini(cub3d, y, x, 0xFF69B4);
}
