/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:36:44 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/04 13:42:27 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_texture(t_cub3d *cub3d)
{
	cub3d->texture[0].addr = (int *)mlx_get_data_addr(cub3d->texture[0].mlx_img, &cub3d->texture[0].bpp, &cub3d->texture[0].line_len, &cub3d->texture[0].endian);
	cub3d->texture[1].addr = (int *)mlx_get_data_addr(cub3d->texture[1].mlx_img, &cub3d->texture[1].bpp, &cub3d->texture[1].line_len, &cub3d->texture[1].endian);
	cub3d->texture[2].addr = (int *)mlx_get_data_addr(cub3d->texture[2].mlx_img, &cub3d->texture[2].bpp, &cub3d->texture[2].line_len, &cub3d->texture[2].endian);
	cub3d->texture[3].addr = (int *)mlx_get_data_addr(cub3d->texture[3].mlx_img, &cub3d->texture[3].bpp, &cub3d->texture[3].line_len, &cub3d->texture[3].endian);
}

void draw_wall(t_cub3d *cub3d, int x0, int *j, int start_wall, int end_wall) 
{
	cub3d->text.texdir = cub3d->map.direction;
	if (cub3d->ray.side == 0)
		cub3d->text.wallx = cub3d->ray.pos_y + cub3d->ray.paperwalldist * cub3d->ray.raydir_y;
	else
		cub3d->text.wallx = cub3d->ray.pos_x + cub3d->ray.paperwalldist * cub3d->ray.raydir_x;
	cub3d->text.wallx -= floor(cub3d->text.wallx);

	cub3d->text.texx =(int)(cub3d->text.wallx * (double)IMG_WIDTH);
	if (cub3d->ray.side == 0 && cub3d->ray.raydir_x > 0)
		cub3d->text.texx = IMG_WIDTH - cub3d->text.texx - 1;
	if (cub3d->ray.side == 1 && cub3d->ray.raydir_y < 0)
		cub3d->text.texx = IMG_WIDTH - cub3d->text.texx - 1;
	cub3d->text.step = 1.0 * IMG_LENGTH / cub3d->ray.lineheight;

	cub3d->text.texpos = (start_wall - cub3d->screen_height / 2 + cub3d->ray.lineheight / 2) * cub3d->text.step;
	init_texture(cub3d);
	while ((*j - 1) < end_wall)
	{
		cub3d->text.texy = (int)cub3d->text.texpos & (IMG_LENGTH - 1);
		cub3d->text.texpos += cub3d->text.step;
		cub3d->img.addr[*j * cub3d->img.line_len / 4 + x0] = cub3d->texture[cub3d->text.texdir].addr[cub3d->text.texy * cub3d->texture[0].line_len / 4 + cub3d->text.texx];
		(*j)++;
	}
}

void draw(t_cub3d *cub3d, int x0, int start_wall, int end_wall) 
{
	int	j;

	j = 0;
	while (j <= start_wall)
	{
		cub3d->img.addr[j * cub3d->img.line_len / 4 + x0] = cub3d->img.floor;
		j++;
	}
	if (j <= end_wall)
		draw_wall(cub3d, x0, &j, start_wall, end_wall);
	while (j <= cub3d->screen_height)
	{
		cub3d->img.addr[j * cub3d->img.line_len / 4 + x0] = cub3d->img.cell;
		j++;
	}
}