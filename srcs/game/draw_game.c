/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:36:44 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/03 13:39:19 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_wall(t_cub3d *cub3d, int x0, int start_wall, int end_wall) 
{
	int	j;

	j = 0;
	while (j <= start_wall)
	{
		cub3d->img.addr[j * cub3d->img.line_len / 4 + x0] = cub3d->img.floor;
		j++;
	}
	while (j <= end_wall)
	{
		cub3d->img.addr[j * cub3d->img.line_len / 4 + x0] = 5;
		j++;
	}
	while (j <= cub3d->screen_height)
	{
		cub3d->img.addr[j * cub3d->img.line_len / 4 + x0] = cub3d->img.cell;
		j++;
	}
}