/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:37:25 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/14 16:26:43 by adegain          ###   ########.fr       */
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
		return (free_struct(&cub3d), 1);
	}
	else
		return (ft_putstr_fd(ERR_ARG, 2), 0);
}
