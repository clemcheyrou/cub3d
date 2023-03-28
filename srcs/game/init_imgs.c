/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:53:18 by adegain           #+#    #+#             */
/*   Updated: 2023/03/28 17:07:38 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_imgs(t_cub3d *cub3d, t_elem *elem)
{
	elem->w = IMG_WIDTH;
	elem->h = IMG_LENGTH;
	cub3d->game.no_img = mlx_xpm_file_to_image(cub3d->game.mlx, elem->no_img,\
		&elem->w, &elem->h);
	if (!cub3d->game.no_img)
		return (ft_putstr_fd(ERR_NO_IMG, 2), 0);
	cub3d->game.so_img = mlx_xpm_file_to_image(cub3d->game.mlx, elem->so_img,\
		&elem->w, &elem->h);
	if (!cub3d->game.so_img)
		return (ft_putstr_fd(ERR_SO_IMG, 2), 0);
	cub3d->game.we_img = mlx_xpm_file_to_image(cub3d->game.mlx, elem->we_img,\
		&elem->w, &elem->h);
	if (!cub3d->game.we_img)
		return (ft_putstr_fd(ERR_WE_IMG, 2), 0);
	cub3d->game.ea_img = mlx_xpm_file_to_image(cub3d->game.mlx, elem->ea_img,\
		&elem->w, &elem->h);
	if (!cub3d->game.ea_img)
		return (ft_putstr_fd(ERR_EA_IMG, 2), 0);
	return (1);
}

void	print_color(int nb, char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (nb < 10)
		s[i] = nb + 48;
	else
		s[i] = nb + 55;
}
	// if (nb >= 16)
	// {
	// 	ft_putnbr_base(nb / 16, color);
	// 	ft_putnbr_base(nb % 16, color);
	// }
	// else
	// 	print_color(nb, color);

void	ft_putnbr_base(int nb, char *hex)
{
	int	i;
	int	res;

	i = 0;
	while (nb)
	{
		res = nb % 16;
		if (res < 10)
			hex[i++] = 48 + res;
		else
			hex[i++] = 55 + res;
		nb /= 16;
	}
}

int	init_colors(t_elem *elem)
{
	elem->cell_hex[0] = '0';
	elem->floor_hex[0] = '0';
	elem->cell_hex[1] = '0';
	elem->floor_hex[1] = '0';
	elem->cell_hex[2] = '0';
	elem->floor_hex[2] = '0';
	ft_putnbr_base(elem->cell[0], &elem->cell_hex[0]);
	ft_putnbr_base(elem->cell[1], &elem->cell_hex[1]);
	ft_putnbr_base(elem->cell[2], &elem->cell_hex[2]);
	ft_putnbr_base(elem->floor[0], &elem->floor_hex[0]);
	ft_putnbr_base(elem->floor[1], &elem->floor_hex[1]);
	ft_putnbr_base(elem->floor[2], &elem->floor_hex[2]);
	printf("elem->cell[0] : %d\n", elem->cell[0]);
	printf("elem->cell_hex[0] : %d\n", elem->cell_hex[0]);
	printf("elem->cell[1] : %d\n", elem->cell[1]);
	printf("elem->cell_hex[1] : %d\n", elem->cell_hex[1]);
	printf("elem->cell[2] : %d\n", elem->cell[2]);
	printf("elem->cell_hex[2] : %d\n", elem->cell_hex[2]);
	printf("elem->floor[0] : %d\n", elem->floor[0]);
	printf("elem->floor_hex[0] : %d\n", elem->floor_hex[0]);
	printf("elem->floor[1] : %d\n", elem->floor[1]);
	printf("elem->floor_hex[1] : %d\n", elem->floor_hex[1]);
	printf("elem->floor[2] : %d\n", elem->floor[2]);
	printf("elem->floor_hex[2] : %d\n", elem->floor_hex[2]);
	return (0);
}