/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:09:18 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/04 16:42:03 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_window(t_cub3d *cub3d)
{
	cub3d->screen_width = 800;
	cub3d->screen_height = 600;
	mlx_get_screen_size(cub3d->game.mlx, &cub3d->sizex, &cub3d->sizey);
	if (cub3d->screen_width > cub3d->sizex)
		cub3d->screen_width = cub3d->sizex;
	if (cub3d->screen_height > cub3d->sizey)
		cub3d->screen_height = cub3d->sizey;
	cub3d->game.win = mlx_new_window(cub3d->game.mlx, cub3d->screen_width, \
		cub3d->screen_height, CHAR_TITLE);
	if (!cub3d->game.win)
		return (0);
	return (1);
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	init_colors(t_cub3d *cub3d, t_elem *elem)
{
	cub3d->img.floor = encode_rgb(elem->floor[0], elem->floor[1], elem->floor[2]);
	cub3d->img.cell = encode_rgb(elem->cell[0], elem->cell[1], elem->cell[2]);
}

int	game(t_cub3d *cub3d)
{
	cub3d->swap_img = 1;
	cub3d->game.mlx = mlx_init();
	init_colors(cub3d, &cub3d->map.elem);
	if (!cub3d->game.mlx)
		return (0);
	if (!init_imgs(cub3d, &cub3d->map.elem))
		return (free_before_exit(cub3d, 0), 0);
	if (!create_window(cub3d))
		return (0);
	cub3d->img.mlx_img = mlx_new_image(cub3d->game.mlx, cub3d->screen_width, cub3d->screen_height);
	cub3d->img.addr = (int *)mlx_get_data_addr(cub3d->img.mlx_img, &cub3d->img.bpp, &cub3d->img.line_len, &cub3d->img.endian);
	def_ray(cub3d);
	cub3d->img.mlx_img2 = mlx_new_image(cub3d->game.mlx, cub3d->screen_width, cub3d->screen_height);
	cub3d->img.addr2 = (int *)mlx_get_data_addr(cub3d->img.mlx_img2, &cub3d->img.bpp, &cub3d->img.line_len, &cub3d->img.endian);
	mlx_hook(cub3d->game.win, 33, 1L << 2, close_btn, cub3d);
	mlx_hook(cub3d->game.win, 2, 1L << 0, move_player, cub3d);
	mlx_loop_hook(cub3d->game.mlx, print_map, cub3d);
	mlx_hook(cub3d->game.win, 3, 1L << 1, release_player, cub3d);
	mlx_loop(cub3d->game.mlx);
	return (1);
}
