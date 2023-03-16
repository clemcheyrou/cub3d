/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:02:12 by adegain           #+#    #+#             */
/*   Updated: 2023/03/13 16:02:36 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_elem_struct(t_cub3d *cub3d)
{
	cub3d->map.elem.no_img = NULL;
	cub3d->map.elem.so_img = NULL;
	cub3d->map.elem.we_img = NULL;
	cub3d->map.elem.ea_img = NULL;
	cub3d->map.elem.floor[0] = -1;
	cub3d->map.elem.floor[1] = -1;
	cub3d->map.elem.floor[2] = -1;
	cub3d->map.elem.cell[0] = -1;
	cub3d->map.elem.cell[1] = -1;
	cub3d->map.elem.cell[2] = -1;
	cub3d->map.elem.flag_floor = 0;
	cub3d->map.elem.flag_cell = 0;
}
