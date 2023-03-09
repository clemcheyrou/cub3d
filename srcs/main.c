/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:37:25 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/09 16:25:40 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_structs(t_cub3d *cub3d)
{
	ft_memset(&cub3d, sizeof(t_cub3d), 0);
	ft_memset(&cub3d->map, sizeof(t_map), 0);
	ft_memset(&cub3d->map.elem, sizeof(t_elem), 0);
	cub3d->map.elem.no_img = NULL;
}

int	main(int ac, char **av)
{
	t_cub3d		cub3d;

	if (ac == 2)
	{
		init_structs(&cub3d);
		if (!check_cub(av[1]))
			return (1);
		if (!get_file(av[1], &cub3d))
			return (1);
		check_file(&cub3d);
		return (0);
	}
	else
		return (ft_putstr_fd(ERR_ARG, 2), 0);
}

