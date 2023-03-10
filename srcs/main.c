/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:37:25 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/10 13:29:43 by ccheyrou         ###   ########.fr       */
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
		check_file(&cub3d);
		return (0);
	}
	else
		return (ft_putstr_fd(ERR_ARG, 2), 0);
}

