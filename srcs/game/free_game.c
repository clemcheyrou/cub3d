/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:00:28 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/20 13:49:48 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_before_exit(t_cub3d *cub3d)
{
	free_struct(cub3d);
	mlx_destroy_window(cub3d->game.mlx, cub3d->game.win);
	//free texture + imgs
	mlx_destroy_display(cub3d->game.mlx);
	free(cub3d->game.mlx);
	exit(0);
}

int	close_btn(t_cub3d *cub3d)
{
	free_before_exit(cub3d);
	exit(0);
}
