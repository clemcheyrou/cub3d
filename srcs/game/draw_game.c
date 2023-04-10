/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:36:44 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/10 14:18:38 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_walls(t_cub3d *cub3d)
{
	if (cub3d->ray.side == 0 && cub3d->ray.raydir_x < 0)
		cub3d->text.texdir = 0;
	if (cub3d->ray.side == 0 && cub3d->ray.raydir_x > 0)
		cub3d->text.texdir = 1;
	if (cub3d->ray.side == 1 && cub3d->ray.raydir_y < 0)
		cub3d->text.texdir = 2;
	if (cub3d->ray.side == 1 && cub3d->ray.raydir_y > 0)
		cub3d->text.texdir = 3;
	if (cub3d->ray.side == 0)
		cub3d->text.wallx = cub3d->ray.pos_y + cub3d->ray.paperwalldist * cub3d->ray.raydir_y;
	else
		cub3d->text.wallx = cub3d->ray.pos_x + cub3d->ray.paperwalldist * cub3d->ray.raydir_x;
	cub3d->text.wallx -= floor(cub3d->text.wallx);
}

void	draw_wall(t_cub3d *cub3d, int x0, int start_wall, int end_wall) 
{
	int	j;

	init_walls(cub3d);
	j = start_wall;
	cub3d->text.texx =(int)(cub3d->text.wallx * (float)cub3d->texture[cub3d->text.texdir].w);
	if (cub3d->ray.side == 0 && cub3d->ray.raydir_x > 0)
		cub3d->text.texx = cub3d->texture[cub3d->text.texdir].w - cub3d->text.texx - 1;
	if (cub3d->ray.side == 1 && cub3d->ray.raydir_y < 0)
		cub3d->text.texx = cub3d->texture[cub3d->text.texdir].w - cub3d->text.texx - 1;
	cub3d->text.step = 1.0 * cub3d->texture[cub3d->text.texdir].h / cub3d->ray.lineheight;

	cub3d->text.texpos = (start_wall - cub3d->screen_height / 2 + cub3d->ray.lineheight / 2) * cub3d->text.step;
	while (j <= end_wall)
	{
		cub3d->text.texy = (int)cub3d->text.texpos & (cub3d->texture[cub3d->text.texdir].h - 1);
		cub3d->text.texpos += cub3d->text.step;
		if (j < cub3d->screen_height && x0 < cub3d->screen_width)
			cub3d->img.addr[j * cub3d->img.line_len / 4 + x0] = cub3d->texture[cub3d->text.texdir].addr[cub3d->text.texy * cub3d->texture[cub3d->text.texdir].line_len / 4 + cub3d->text.texx];
		j++;
	}
}

void	draw(t_cub3d *cub3d, int x0, int start_wall, int end_wall) 
{
	int	j;

	j = 0;

	//if (start_wall > cub3d->screen_height)
	//	return ;
	/*while (j < start_wall)
	{
		cub3d->img.addr[j * cub3d->img.line_len / 4 + x0] = cub3d->img.floor;
		j++;
	}*/
	if (j <= end_wall)
		draw_wall(cub3d, x0, start_wall, end_wall);
	/*j = end_wall - 1;
	while (j < cub3d->screen_height)
	{
		cub3d->img.addr[j * cub3d->img.line_len / 4 + x0] = cub3d->img.cell;
		j++;
	}*/
}
