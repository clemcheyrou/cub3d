/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:09:18 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/22 15:56:42 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
int	execute_dda(t_cub3d *cub3d)
{
	int		pixel_index;
	int		x;
	int		y;

	y = 0;
	//1ere etape
	printf("mapx %d mapy %d\n", cub3d->ray.map_x, cub3d->ray.map_y);
	while (cub3d->ray.hit == 0) 
    {
		if (cub3d->ray.sidedist_x < cub3d->ray.sidedist_y) 
        { 
			cub3d->ray.sidedist_x += cub3d->ray.deltadist_x ; 
			cub3d->ray.map_x += cub3d->ray.step_x ; 
			cub3d->ray.side = 0 ;
        } 
        else 
        { 
			cub3d->ray.sidedist_y += cub3d->ray.deltadist_y ; 
			cub3d->ray.map_y += cub3d->ray.step_y ; 
			cub3d->ray.side = 1 ; 
        }
		if (cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y] == '1')
			cub3d->ray.hit = 1;
	}
	//2e etape
	if (cub3d->ray.side == 0)
		cub3d->ray.paperwalldist = (cub3d->ray.sidedist_x - cub3d->ray.deltadist_x);
	else
		cub3d->ray.paperwalldist = (cub3d->ray.sidedist_y - cub3d->ray.deltadist_y); 
	cub3d->ray.lineheight = cub3d->screen_height / cub3d->ray.paperwalldist;	
	cub3d->ray.drawstart = -cub3d->ray.lineheight / (2 + cub3d->screen_height) / 2; 
    if (cub3d->ray.drawstart < 0)
		cub3d->ray.drawstart = 0 ; 
    cub3d->ray.drawend = cub3d->ray.lineheight / (2 + cub3d->screen_height) / 2; 
    if(cub3d->ray.drawend >= cub3d->ray.lineheight)
		cub3d->ray.drawend = cub3d->screen_height - 1;
	//3e etape
	cub3d->img.mlx_img = mlx_new_image(cub3d->game.mlx, cub3d->screen_width, cub3d->screen_height);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.mlx_img, &cub3d->img.bpp, \
		&cub3d->img.line_len, &cub3d->img.endian);
	printf("ppw %f\n",cub3d->ray.paperwalldist);
	printf("lineheightt %d\n",cub3d->ray.lineheight);
	printf("drawend %d\n",cub3d->ray.drawend);
	printf("drastart %d\n",cub3d->ray.drawstart);
	while (y <= cub3d->screen_height)
	{
		x = 0;
		while (x < cub3d->ray.drawend)
		{
			pixel_index = (y * cub3d->ray.drawend) + \
			(x * (cub3d->img.bpp / 8));
			cub3d->img.addr[pixel_index] = 255;
			cub3d->img.addr[pixel_index + 1] = 255;
			cub3d->img.addr[pixel_index + 2] = 0;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win, \
	cub3d->img.mlx_img, cub3d->screen_width, cub3d->screen_height);
	return (0);
}

void	init_struct_ray(t_cub3d *cub3d)
{
	cub3d->screen_width = 800;
	cub3d->screen_height = 600;
	cub3d->left_key = 0;
	cub3d->right_key = 0;
	cub3d->move = 0;
	cub3d->ray.dir_x = 0;
	cub3d->ray.dir_y = 0;
	cub3d->ray.plan_x = 0;
	cub3d->ray.plan_y = 0;
	cub3d->ray.deltadist_y = fabs(cub3d->ray.dir_y);
	cub3d->ray.deltadist_x = fabs(cub3d->ray.dir_x);	
	if (cub3d->map.direction == N)
	{
		cub3d->ray.dir_y = -1;
		cub3d->ray.plan_x = 0.66;
	}
	if (cub3d->map.direction == S)
	{
		cub3d->ray.dir_x = 1;
		cub3d->ray.plan_y = -0.66;
	}
	if (cub3d->map.direction == W)
	{
		cub3d->ray.dir_y = -1;
		cub3d->ray.plan_x = -0.66;
	}
	if (cub3d->map.direction == E)
	{
		cub3d->ray.dir_y = 1;
		cub3d->ray.plan_x = 0.66;
	}
	cub3d->ray.cam_x = 0;
	cub3d->ray.map_x = cub3d->ray.pos_x;
	cub3d->ray.map_y = cub3d->ray.pos_y;
	if (cub3d->ray.dir_y == 0)
		cub3d->ray.deltadist_y = exp(30);
	if (cub3d->ray.dir_x == 0)
		cub3d->ray.deltadist_x = exp(30);
	cub3d->ray.hit = 0;
	cub3d->ray.step_y = 1;
	cub3d->ray.sidedist_y = 1 + cub3d->ray.deltadist_y;
	cub3d->ray.step_x = 1;
	cub3d->ray.sidedist_x = 1 + cub3d->ray.deltadist_x;
	if (cub3d->ray.dir_y < 0)
	{
		cub3d->ray.step_y = -1;
		cub3d->ray.sidedist_y = cub3d->ray.deltadist_y;
	}
	if (cub3d->ray.dir_x < 0)
	{
		cub3d->ray.step_x = -1;
		cub3d->ray.sidedist_x = cub3d->ray.deltadist_x;
	}
}*/

int	create_window(t_cub3d *cub3d)
{
	cub3d->screen_width = 2300;
	cub3d->screen_height = 1200;
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

int	move_player(int keycode, t_cub3d *cub3d)
{
	if (keycode == W_K)
		cub3d->move = 1;
	else if (keycode == A_K)
		cub3d->move = 2;
	else if (keycode == S_K)
		cub3d->move = 3;
	else if (keycode == D_K)
		cub3d->move = 4;
	if (keycode == LEFT_A)
		cub3d->ray.cam_x += 0.1;
	else if (keycode == RIGHT_A)
		cub3d->ray.cam_x -= 0.1;
	else if (keycode == ESC_K)
		free_before_exit(cub3d);
	return (1);
}

int	release_player(int keycode, t_cub3d *cub3d)
{
	if (keycode == W_K)
		cub3d->move = 0;
	else if (keycode == A_K)
		cub3d->move = 0;
	else if (keycode == S_K)
		cub3d->move = 0;
	else if (keycode == D_K)
		cub3d->move = 0;
	return (1);
}

void	def_ray(t_cub3d *cub3d)
{
	cub3d->screen_width = 800;
	cub3d->screen_height = 600;
	cub3d->left_key = 0;
	cub3d->right_key = 0;
	cub3d->move = 0;
	
	if (cub3d->map.direction == 0)
	{
		cub3d->ray.dir_x = -1;
		cub3d->ray.dir_y = 0;
		cub3d->ray.plan_x = 0;
		cub3d->ray.plan_y = 0.66;
	}
}

void mlx_draw_line(t_cub3d *cub3d, int x0, int y0, int x1, int y1, int color) 
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1) {
        mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, x0, y0, color);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void	ray_pos(t_cub3d *cub3d)
{
	int	x;
	
	x = 0;
	ft_memset(&cub3d->ray, 0, sizeof(cub3d));
	cub3d->ray.hit = 0;
	cub3d->ray.paperwalldist = 0;
	while (x < cub3d->screen_width)
	{
		cub3d->ray.map_x = cub3d->x;
		cub3d->ray.map_y = cub3d->y;
		cub3d->ray.cam_x = (2 * x) / ((double)cub3d->screen_width - 1);
		cub3d->ray.raydir_x = cub3d->ray.dir_x + cub3d->ray.plan_x * cub3d->ray.cam_x;
		cub3d->ray.raydir_y = cub3d->ray.dir_y + cub3d->ray.plan_y * cub3d->ray.cam_x;
		printf("cub3d->ray.map_x  %d \n", cub3d->ray.map_x);
		printf("cub3d->ray.map_y  %d \n", cub3d->ray.map_y);
		
		//longueur du rayon de la position actuelle au côté x ou y suivant
		if (cub3d->ray.raydir_x == 0)
			cub3d->ray.deltadist_x = fabs(cub3d->ray.raydir_x);
		else
			cub3d->ray.deltadist_x = exp(30);
		if (cub3d->ray.raydir_y == 0)
			cub3d->ray.deltadist_y = fabs(cub3d->ray.raydir_y);
		else
			cub3d->ray.deltadist_y = exp(30);
		cub3d->ray.hit = 0;
	
		//calculer le pas et la sideDist initiale
		if (cub3d->ray.dir_x < 0)
		{
			cub3d->ray.step_x = -1;
			cub3d->ray.sidedist_x = 0;
		}
		else 
		{
			cub3d->ray.step_x = 1;
			cub3d->ray.sidedist_x = cub3d->ray.deltadist_x;
		}
		if (cub3d->ray.raydir_y < 0)
		{
			cub3d->ray.step_y = -1;
			cub3d->ray.sidedist_y = cub3d->ray.deltadist_y;
		}
		else 
		{
			cub3d->ray.step_y = 1;
			cub3d->ray.sidedist_y = cub3d->ray.deltadist_y;
		}

		//exécute DDA
		while (cub3d->ray.hit == 0) 
		{
			if (cub3d->ray.sidedist_y > cub3d->ray.sidedist_x) 
			{ 
				cub3d->ray.sidedist_y += cub3d->ray.deltadist_y ; 
				cub3d->ray.map_y += cub3d->ray.step_y; 
				cub3d->ray.side = 0 ;
				printf("1 cub3d->map.map[%d][%d]  %c \n", cub3d->ray.map_x, cub3d->ray.map_y, cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y]);
			} 
			else 
			{ 
				cub3d->ray.sidedist_x += cub3d->ray.deltadist_x ; 
				cub3d->ray.map_x += cub3d->ray.step_x; 
				cub3d->ray.side = 1 ; 
				printf("2 cub3d->map.map[%d][%d]  %c \n", cub3d->ray.map_x, cub3d->ray.map_y, cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y]);
			}
			if (cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y] == '1' 
				|| cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y] == 'X')
				cub3d->ray.hit = 1;
		}
		printf("cub3d->map.map[%d][%d]  %c \n", cub3d->ray.map_x, cub3d->ray.map_y, cub3d->map.map[cub3d->ray.map_x][cub3d->ray.map_y]);
		printf("cub3d->ray.side %d \n", cub3d->ray.side);
		printf("cub3d->ray.sidedist_y  %f \n", cub3d->ray.sidedist_y);
		printf("cub3d->ray.sidedist_x  %f \n", cub3d->ray.sidedist_x);
		if (cub3d->ray.side == 0)
			cub3d->ray.paperwalldist = (cub3d->ray.sidedist_x - cub3d->ray.deltadist_x);
		else
			cub3d->ray.paperwalldist = (cub3d->ray.sidedist_y - cub3d->ray.deltadist_y); 
		printf("cub3d->ray.paperwalldist %f \n", cub3d->ray.paperwalldist);
		
		cub3d->ray.lineheight = (int)(cub3d->screen_height / cub3d->ray.paperwalldist);	
		
		printf("cub3d->screen_height %f \n", cub3d->screen_height);
		printf("cub3d->ray.lineheight %d \n", cub3d->ray.lineheight);
		cub3d->ray.drawstart = -cub3d->ray.lineheight / (2 + cub3d->screen_height) / 2; 
		if (cub3d->ray.drawstart < 0)
			cub3d->ray.drawstart = 0 ; 
		cub3d->ray.drawend = cub3d->ray.lineheight / (2 + cub3d->screen_height) / 2; 
		printf("cub3d->ray.drawend %d \n", cub3d->ray.drawend);
		if(cub3d->ray.drawend >= cub3d->screen_height)
			cub3d->ray.drawend = cub3d->screen_height - 1;
		
		cub3d->img.mlx_img = mlx_new_image(cub3d->game.mlx, cub3d->screen_width, cub3d->screen_height);
		cub3d->img.addr = mlx_get_data_addr(cub3d->img.mlx_img, &cub3d->img.bpp, \
		&cub3d->img.line_len, &cub3d->img.endian);
		
		printf("x %d \n", x);
		printf("cub3d->ray.paperwalldist %f \n", cub3d->ray.paperwalldist);
		mlx_draw_line(cub3d, x, cub3d->ray.drawstart, x, cub3d->ray.drawend, 0xFFFFFF);
		x++;
	}
	
}

int	game(t_cub3d *cub3d)
{
	cub3d->game.mlx = mlx_init();
	if (!cub3d->game.mlx)
		return (0);
	if (!create_window(cub3d))
		return (0);
	cub3d->img.mlx_img = mlx_new_image(cub3d->game.mlx, cub3d->screen_width, cub3d->screen_height);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.mlx_img, &cub3d->img.bpp, \
		&cub3d->img.line_len, &cub3d->img.endian);
	def_ray(cub3d);
	ray_pos(cub3d);
	mlx_hook(cub3d->game.win, 33, 1L << 2, close_btn, cub3d);
	mlx_hook(cub3d->game.win, 2, 1L << 0, move_player, cub3d);
	//mlx_loop_hook(cub3d->game.mlx, print_map, cub3d);
	mlx_hook(cub3d->game.win, 3, 1L << 1, release_player, cub3d);
	mlx_loop(cub3d->game.mlx);
	return (1);
}
