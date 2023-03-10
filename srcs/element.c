/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:49:22 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/10 16:07:08 by adegain          ###   ########.fr       */
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

int	parse_imgs(char *line, t_cub3d *cub3d, int type)
{
	line = ft_strtrim(line, " ");
	if (!line)
		return (ft_putstr_fd(ERR_DEF, 2), 0);
	if (type == 1 && cub3d->map.elem.no_img == NULL)
		return(cub3d->map.elem.no_img = ft_strdup(line), 1);
	if (type == 2 && cub3d->map.elem.so_img == NULL)
		return(cub3d->map.elem.so_img = ft_strdup(line), 1);
	if (type == 3 && cub3d->map.elem.we_img == NULL)
		return(cub3d->map.elem.we_img = ft_strdup(line), 1);
	if (type == 4 && cub3d->map.elem.ea_img == NULL)
		return(cub3d->map.elem.ea_img = ft_strdup(line), 1);
	return (ft_putstr_fd(ERR_DBL, 2), free_struct(cub3d), 0);
}

int	colors_tab(char *line, t_elem elem, int type)
{
	char	**tab;
	int		i;

	tab = ft_split(line, ',');
	i = 0;

	if (!tab || !tab[3])
		return (0);
	while (tab[i])
	{
		if (type == 5)
		{
			elem.floor[i] = ft_atoi(tab[i]);
			elem.flag_floor++;
		}
		if (type == 6)
		{
			elem.cell[i] = ft_atoi(tab[i]);
			elem.flag_cell++;
		}
		free(tab[i]);
		i++;
	}
	free(tab);
	if (elem.flag_cell > 3 || elem.flag_floor > 3)
		return (0); 
	return (1);
}

int	check_color_param(char *line)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (line[i])
	{
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == ' ')
			return (0);
		if (line[i] == ',' && !ft_isdigit(line[i + 1]))
			return (0);
		if (line[i] == ',')
			flag++;
		i++;
	}
	if (flag > 2)
		return (0);
}

int	parse_color(char *line, t_cub3d *cub3d, int type)
{
	line = ft_strtrim(line, " ");
	if (!line)
		return (ft_putstr_fd(ERR_DEF, 2), 0);
	if (!check_color_param(line))
		return (ft_putstr_fd(ERR_CLR, 2), 0);
	if (cub3d->map.elem.flag_cell > 3 || cub3d->map.elem.flag_floor > 3)
	{
		if (type == 5)
		{
			if (!colors_tab(line, cub3d->map.elem, type))
				return (ft_putstr_fd(ERR_DBL, 2), free_struct(cub3d), 0);
		}
		if (type == 6)
		{
			if (!colors_tab(line, cub3d->map.elem, type))
				return (ft_putstr_fd(ERR_DBL, 2), free_struct(cub3d), 0);
		}
	}
	return (1); // je ne suis pas sure
}

int	find_elem(char *line, t_cub3d *cub3d)
{
	int				i;
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
	return (ft_putstr_fd(ERR_DEF, 2), free_struct(cub3d), 0);
}

int check_file(t_cub3d *cub3d)
{
	int i;

	i = 0;
	while (cub3d->file[i])
	{
		if (ft_isalpha(cub3d->file[i][0]))
			if (!find_elem(cub3d->file[i], cub3d))
				return (1);
		i++;
	}
	if (!cub3d->map.elem.no_img || !cub3d->map.elem.so_img
		|| !cub3d->map.elem.we_img || !cub3d->map.elem.ea_img)
		return (ft_putstr_fd(ERR_DEF, 2), free_struct(cub3d), 0);
	// si on défini les valeurs de floor et de cell a -1 on peut les vérifier ici 
	return (1);
}
