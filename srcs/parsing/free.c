/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:29:40 by adegain           #+#    #+#             */
/*   Updated: 2023/04/11 13:35:16 by adegain          ###   ########.fr       */
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
	{
		free_array(cub3d->file);
		free(cub3d->file);
	}
	if (cub3d->map.map)
	{
		free_array(cub3d->map.map);
		free(cub3d->map.map);
	}
	if (cub3d->map.elem.no_img)
		free(cub3d->map.elem.no_img);
	if (cub3d->map.elem.so_img)
		free(cub3d->map.elem.so_img);
	if (cub3d->map.elem.we_img)
		free(cub3d->map.elem.we_img);
	if (cub3d->map.elem.ea_img)
		free(cub3d->map.elem.ea_img);
}

void	print_struct(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	if (cub3d->map.elem.no_img)
		printf("no_img : [%s]\n", cub3d->map.elem.no_img);
	if (cub3d->map.elem.so_img)
		printf("so_img : [%s]\n", cub3d->map.elem.so_img);
	if (cub3d->map.elem.we_img)
		printf("we_img : [%s]\n", cub3d->map.elem.we_img);
	if (cub3d->map.elem.ea_img)
		printf("ea_img : [%s]\n", cub3d->map.elem.ea_img);
	while (i < 3)
	{
		printf("floor[%d] : [%d]\n", i, cub3d->map.elem.floor[i]);
		printf("cell[%d] : [%d]\n", i, cub3d->map.elem.cell[i]);
		i++;
	}
	i = 0;
	while (cub3d->map.map[i])
	{
		printf("%d [%s]\n", i, cub3d->map.map[i]);
		i++;
	}
}
