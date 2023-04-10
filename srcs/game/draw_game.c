/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:36:44 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/10 14:51:52 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_cub3d *cub3d)
{
	cub3d->texture[0].addr = (int *)mlx_get_data_addr(cub3d->texture[0].mlx_img, &cub3d->texture[0].bpp, &cub3d->texture[0].line_len, &cub3d->texture[0].endian);
	cub3d->texture[1].addr = (int *)mlx_get_data_addr(cub3d->texture[1].mlx_img, &cub3d->texture[1].bpp, &cub3d->texture[1].line_len, &cub3d->texture[1].endian);
	cub3d->texture[2].addr = (int *)mlx_get_data_addr(cub3d->texture[2].mlx_img, &cub3d->texture[2].bpp, &cub3d->texture[2].line_len, &cub3d->texture[2].endian);
	cub3d->texture[3].addr = (int *)mlx_get_data_addr(cub3d->texture[3].mlx_img, &cub3d->texture[3].bpp, &cub3d->texture[3].line_len, &cub3d->texture[3].endian);
}

void	init_walls(t_ray *ray, t_text *text)
{
	if (ray->side == 0 && ray->raydir_x < 0)
		text->texdir = 0;
	if (ray->side == 0 && ray->raydir_x > 0)
		text->texdir = 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		text->texdir = 2;
	if (ray->side == 1 && ray->raydir_y > 0)
		text->texdir = 3;
	if (ray->side == 0)
		text->wallx = ray->pos_y + ray->paperwalldist * ray->raydir_y;
	else
		text->wallx = ray->pos_x + ray->paperwalldist * ray->raydir_x;
	text->wallx -= floor(text->wallx);
}

void	draw_wall(t_cub3d *cub3d, int x0, t_ray *ray, t_text *text)
{
	int	j;

	init_walls(ray, text);
	j = ray->drawstart;
	text->texx = (int)(text->wallx * (float)cub3d->texture[text->texdir].w);
	if (ray->side == 0 && ray->raydir_x > 0)
		text->texx = cub3d->texture[text->texdir].w - text->texx - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		text->texx = cub3d->texture[text->texdir].w - text->texx - 1;
	text->step = 1.0 * cub3d->texture[text->texdir].h / ray->lineheight;
	text->texpos = (ray->drawstart - cub3d->screen_height / 2 + \
		ray->lineheight / 2) * text->step;
	while (j <= ray->drawend)
	{
		text->texy = (int)text->texpos & (cub3d->texture[text->texdir].h - 1);
		text->texpos += text->step;
		if (j < cub3d->screen_height && x0 < cub3d->screen_width)
			cub3d->img.addr[j * cub3d->img.line_len / 4 + x0] = \
				cub3d->texture[text->texdir].addr[text->texy \
				* cub3d->texture[text->texdir].line_len / 4 + text->texx];
		j++;
	}
}
