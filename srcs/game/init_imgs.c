/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:53:18 by adegain           #+#    #+#             */
/*   Updated: 2023/04/10 14:03:57 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_imgs(t_cub3d *cub3d, t_elem *elem)
{
	cub3d->texture[0].mlx_img = mlx_xpm_file_to_image(cub3d->game.mlx, \
	elem->no_img, &cub3d->texture[0].w, &cub3d->texture[0].h);
	if (!cub3d->texture[0].mlx_img)
		return (ft_putstr_fd(ERR_NO_IMG, 2), 0);
	cub3d->texture[1].mlx_img = mlx_xpm_file_to_image(cub3d->game.mlx, \
	elem->so_img, &cub3d->texture[1].w, &cub3d->texture[1].h);
	if (!cub3d->texture[1].mlx_img)
		return (ft_putstr_fd(ERR_SO_IMG, 2), 0);
	cub3d->texture[2].mlx_img = mlx_xpm_file_to_image(cub3d->game.mlx, \
	elem->we_img, &cub3d->texture[2].w, &cub3d->texture[2].h);
	if (!cub3d->texture[2].mlx_img)
		return (ft_putstr_fd(ERR_WE_IMG, 2), 0);
	cub3d->texture[3].mlx_img = mlx_xpm_file_to_image(cub3d->game.mlx, \
	elem->ea_img, &cub3d->texture[3].w, &cub3d->texture[3].h);
	if (!cub3d->texture[3].mlx_img)
		return (ft_putstr_fd(ERR_EA_IMG, 2), 0);
	return (1);
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	init_colors(t_cub3d *cub3d, t_elem *elem)
{
	cub3d->img.floor = encode_rgb(elem->floor[0], elem->floor[1], \
	elem->floor[2]);
	cub3d->img.cell = encode_rgb(elem->cell[0], elem->cell[1], elem->cell[2]);
}
