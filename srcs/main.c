/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:23:11 by adegain           #+#    #+#             */
/*   Updated: 2023/03/23 16:52:12 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d		cub3d;

	if (ac == 2)
	{
		ft_memset(&cub3d, 0, sizeof(cub3d));
		if (!check_cub(av[1]))
			return (1);
		if (!get_file(av[1], &cub3d))
			return (1);
		if (!check_file(&cub3d))
			return (1);
		//print_struct(&cub3d);
		if (!check_map(&cub3d))
			return (1);
		game(&cub3d);
		return (free_struct(&cub3d), 1);
	}
	else
		return (ft_putstr_fd(ERR_ARG, 2), 0);
}
