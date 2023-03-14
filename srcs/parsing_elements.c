/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:49:22 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/14 14:01:14 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef int(*t_fp_pointer)();

typedef struct s_parse
{
	char			*str;
	int				len;
	int				type;
	t_fp_pointer	fp;
}	t_parse;

int	find_elem(char *line, t_cub3d *cub3d)
{
	int		i;
	t_parse	storage [7] = {
	{"NO ", 3, 1, parse_imgs},
	{"SO ", 3, 2, parse_imgs},
	{"WE ", 3, 3, parse_imgs},
	{"EA ", 3, 4, parse_imgs},
	{"F ", 2, 5, parse_color},
	{"C ", 2, 6, parse_color},
	{NULL, 0, 0, NULL}
	};

	i = 0;
	while (storage[i].str)
	{
		if (!ft_strncmp(line, storage[i].str, storage[i].len))
			return (storage[i].fp(line + storage[i].len, cub3d, storage[i].type));
		i++;
	}
	return (1);
}

int	check_file(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	init_elem_struct(cub3d);
	while (cub3d->file[i])
	{
		if (ft_isalpha(cub3d->file[i][0]) && cub3d->map.elem_nb != 6)
			if (!find_elem(cub3d->file[i], cub3d))
				return (ft_putstr_fd(ERR_DEF, 2), free_struct(cub3d), 0);
		if (cub3d->map.elem_nb == 6)
			return (i++, generate_map(cub3d->file + i, cub3d));
		i++;
	}
	return (ft_putstr_fd(ERR_DEF, 2), free_struct(cub3d), 0);
}
