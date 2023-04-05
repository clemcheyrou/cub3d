/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:53:18 by adegain           #+#    #+#             */
/*   Updated: 2023/04/05 15:40:32 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_imgs(t_cub3d *cub3d, t_elem *elem)
{
	elem->w = IMG_WIDTH;
	elem->h = IMG_LENGTH;
	cub3d->texture[0].mlx_img = mlx_xpm_file_to_image(cub3d->game.mlx, elem->no_img,\
		&elem->w, &elem->h);
	if (!cub3d->texture[0].mlx_img)
		return (ft_putstr_fd(ERR_NO_IMG, 2), 0);
	cub3d->texture[1].mlx_img = mlx_xpm_file_to_image(cub3d->game.mlx, elem->so_img,\
		&elem->w, &elem->h);
	if (!cub3d->texture[1].mlx_img)
		return (ft_putstr_fd(ERR_SO_IMG, 2), 0);
	cub3d->texture[2].mlx_img = mlx_xpm_file_to_image(cub3d->game.mlx, elem->we_img,\
		&elem->w, &elem->h);
	if (!cub3d->texture[2].mlx_img)
		return (ft_putstr_fd(ERR_WE_IMG, 2), 0);
	cub3d->texture[3].mlx_img = mlx_xpm_file_to_image(cub3d->game.mlx, elem->ea_img,\
		&elem->w, &elem->h);
	if (!cub3d->texture[3].mlx_img)
		return (ft_putstr_fd(ERR_EA_IMG, 2), 0);
	return (1);
}
