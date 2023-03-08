/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:49:22 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/08 19:18:52 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef int(*t_fp_pointer)();

typedef struct s_elem
{
	char			*str;
	int				len;
	int				dir;
}	t_elem;

//if is alpha rentrer dans cette fct
int	find_elem(char *line)
{
	int				i;
	const t_elem	storage [7] = {
	{"NO ", 3, 1},
	{"SO ", 3, 2},
	{"WE ", 3, 3},
	{"EA ", 3, 4},
	{"F ", 2, 5},
	{"C ", 2, 6},
	{NULL, 0, 0}
	};

	i = 0;
	while (storage[i].str)
	{
		if (!ft_strncmp(line, storage[i].str, storage[i].len))
			return (ft_putstr_fd("OK\n", 1), 1); //id existe, cependant regarder si doublon
		i++;
	}
	//free tout car id n'existe pas
	return (ft_putstr_fd("KO\n", 2), 0);
}
