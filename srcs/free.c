/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:29:40 by adegain           #+#    #+#             */
/*   Updated: 2023/03/10 16:07:01 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **var)
{
	if (*var)
	{
		while (*var)
		{
			free(*var);
			var++;
		}
		free(*var);
	}
}

void	free_struct(t_cub3d *cub3d)
{
	if (cub3d->file)
		free_array(cub3d->file);
	if (cub3d->map.map)
		free_array(cub3d->file);
	if (cub3d->map.elem.no_img)
		free(cub3d->map.elem.no_img);
	if (cub3d->map.elem.so_img)
		free(cub3d->map.elem.so_img);
	if (cub3d->map.elem.we_img)
		free(cub3d->map.elem.we_img);
	if (cub3d->map.elem.ea_img)
		free(cub3d->map.elem.ea_img);
}
