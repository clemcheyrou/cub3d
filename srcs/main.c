/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:37:25 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/08 19:41:19 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	char		**map;
	int 		i = 0;

	if (ac == 2)
	{
		if (!check_cub(av[1]))
			return (1);
		map = get_map(av[1]);
		if (!map)
			return (ft_putstr_fd("Error\n", 2), 1);
		while (map[i])
		{
			if (ft_isalpha(map[i][0]))
				if (!find_elem(map[i]))
					return (ft_putstr_fd(ERR_DEF, 2), 1); //free_struct
			if (ft_strchr(map[i], '1') && !(ft_strchr(map[i], 'F') || ft_strchr(map[i], 'C'))
					&& elem_nb != 6)
				return (ft_putstr_fd(ERR_DEF, 2), 1);	
			i++;
		}
	}
	else
		return (ft_putstr_fd("Error\n", 2), 1);
}

