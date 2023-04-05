/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:00:28 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/05 16:47:05 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_before_exit(t_cub3d *cub3d, int flag)
{
	free_struct(cub3d);
	if (flag != 0)
		mlx_destroy_window(cub3d->game.mlx, cub3d->game.win);
	free_imgs(cub3d);
	mlx_destroy_display(cub3d->game.mlx);
	free(cub3d->game.mlx);
	exit(0);
}

int	close_btn(t_cub3d *cub3d)
{
	free_before_exit(cub3d, 1);
	exit(0);
}

void	free_imgs(t_cub3d *cub3d)
{
	if (cub3d->texture[0].mlx_img)
		mlx_destroy_image(cub3d->game.mlx, cub3d->texture[0].mlx_img);
	if (cub3d->texture[1].mlx_img)
		mlx_destroy_image(cub3d->game.mlx, cub3d->texture[1].mlx_img);
	if (cub3d->texture[2].mlx_img)
		mlx_destroy_image(cub3d->game.mlx, cub3d->texture[2].mlx_img);
	if (cub3d->texture[3].mlx_img)
		mlx_destroy_image(cub3d->game.mlx, cub3d->texture[3].mlx_img);
	mlx_destroy_image(cub3d->game.mlx, cub3d->img.mlx_img);
	mlx_destroy_image(cub3d->game.mlx, cub3d->img.mlx_img2);

}
