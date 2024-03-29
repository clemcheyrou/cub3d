/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:44:31 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/10 19:28:21 by adegain          ###   ########.fr       */
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
