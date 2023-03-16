/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:09:18 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/16 17:26:19 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	init_image(t_cub3d *cub3d)
{
	
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "src/img/collect.xpm", \
		&vars->img_width, &vars->img_height);
	vars->floor = mlx_xpm_file_to_image(vars->mlx, "src/img/floor.xpm", \
		&vars->img_width, &vars->img_height);
	vars->player = mlx_xpm_file_to_image(vars->mlx, "src/img/exit.xpm", \
		&vars->img_width, &vars->img_height);
}

void	letter_to_image(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->map.map[x][y] == '1')
		mlx_put_image_to_window(cub3d->mlx, cub3d->game.win, \
			cub3d->wall, y * 60, x * 60);
	else if (cub3d->map.map[x][y] == '0')
		mlx_put_image_to_window(cub3d->mlx, cub3d->game.win, \
			cub3d->floor, y * 60, x * 60);
	else if (cub3d->map.map[x][y] == 'N')
		mlx_put_image_to_window(cub3d->mlx, cub3d->game.win, \
			cub3d->player, y * 60, x * 60);
	else if (cub3d->map.map[x][y] == 'W')
		mlx_put_image_to_window(cub3d->mlx, cub3d->game.win, \
			cub3d->player, y * 60, x * 60);
	else if (cub3d->map.map[x][y] == 'S')		
		mlx_put_image_to_window(cub3d->mlx, cub3d->game.win, \
			cub3d->player, y * 60, x * 60);
	else if (cub3d->map.map[x][y] == 'O')		
		mlx_put_image_to_window(cub3d->mlx, cub3d->game.win, \
			cub3d->player, y * 60, x * 60);

}

void	print_map(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	while (cub3d->map.map[x])
	{
		y = 0;
		while (cub3d->map.map[x][y])
		{
			letter_to_image(cub3d, x, y);
			y++;
		}
		x++;
	}
}*/


int	game(t_cub3d *cub3d)
{
	cub3d->game.mlx = mlx_init();
	if (!cub3d->game.mlx)
		return (0); //free
	cub3d->game.win = mlx_new_window(cub3d->game.mlx, cub3d->map.map_length * 60, \
		cub3d->map.map_height * 60, CHAR_TITLE);
	if (!cub3d->game.win)
	{
		free(cub3d->game.win);
		return (0);
	}
	//mlx_loop_hook(cub3d->game.mlx, &render, &cub3d);
	//init_image(cub3d);
	//if (miss_img(cub3d))
	//	return (0); //free
	//print_map(cub3d);
	return (1);
}
