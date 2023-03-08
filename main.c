/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:37:25 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/08 18:13:03 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	char		**map;

	if (ac == 2)
	{
		if (!check_cub(av[1]))
			return (1);
		map = get_map(av[1]);
		if (!map)
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	return (ft_putstr_fd("Error\n", 2), 1);
}

