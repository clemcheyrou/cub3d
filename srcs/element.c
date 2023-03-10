/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:49:22 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/10 19:33:01 by ccheyrou         ###   ########.fr       */
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

int	check_img_param(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	parse_imgs(char *line, t_cub3d *cub3d, int type)
{
	line = ft_strtrim(line, " ");
	if (!line)
		return (ft_putstr_fd(ERR_DEF, 2), 0);
	if (!check_img_param(line))
		return (ft_putstr_fd(ERR_FIL, 2), free_struct(cub3d), 0);
	if (type == 1 && cub3d->map.elem.no_img == NULL)
		return(cub3d->map.elem_nb++, cub3d->map.elem.no_img = ft_strdup(line), 1);
	if (type == 2 && cub3d->map.elem.so_img == NULL)
		return(cub3d->map.elem_nb++, cub3d->map.elem.so_img = ft_strdup(line), 1);
	if (type == 3 && cub3d->map.elem.we_img == NULL)
		return(cub3d->map.elem_nb++, cub3d->map.elem.we_img = ft_strdup(line), 1);
	if (type == 4 && cub3d->map.elem.ea_img == NULL)
		return(cub3d->map.elem_nb++, cub3d->map.elem.ea_img = ft_strdup(line), 1);
	return (ft_putstr_fd(ERR_DBL, 2), free_struct(cub3d), 0);
}

int	ft_atoi_cub(const char *nptr)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		res = -1;
		return (res);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res);
}

int	colors_tab(char *line, t_elem *elem, int type)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(line, ',');
	if (!tab || tab[4] != NULL) // ou ft_strlen de tab ?
		return (0);
	while (tab[i])
	{
		if (ft_alldigit(tab[i]))
			return (ft_putstr_fd(ERR_CLR, 2), 0);
		if (type == 5)
		{
			elem->floor[i] = ft_atoi_cub(tab[i]);
			elem->flag_floor++;
			if (elem->floor[i] < 0 || elem->floor[i] > 255)
				return (ft_putstr_fd(ERR_CLR, 2), 0);
		}
		if (type == 6)
		{
			elem->cell[i] = ft_atoi_cub(tab[i]);
			elem->flag_cell++;
			if (elem->cell[i] < 0 || elem->cell[i] > 255)
				return (ft_putstr_fd(ERR_CLR, 2), 0);
		}
		free(tab[i]);
		i++;
	}
	free(tab);
	if (elem->flag_cell > 3 || elem->flag_floor > 3)
		return (ft_putstr_fd(ERR_DBL, 2), 0); 
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
		if (line[i] == ',' && !ft_isdigit(line[i + 1])) // à vérifier pour le chiffre apres la virgule
			return (0);
		if (line[i] == ',')
			flag++;
		i++;
	}
	if (flag > 2)
		return (0);
	return (1);
}

int	parse_color(char *line, t_cub3d *cub3d, int type)
{
	line = ft_strtrim(line, " ");
	if (!line)
		return (ft_putstr_fd(ERR_DEF, 2), 0);
	if (!check_color_param(line))
		return (ft_putstr_fd(ERR_CLR, 2), 0);
	if (!colors_tab(line, &cub3d->map.elem, type))
		return (free_struct(cub3d), 0);
	return (cub3d->map.elem_nb++, 1);
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
	return (1); // à changer plus tard 
}

void	init_elem_struct(t_cub3d *cub3d)
{
	cub3d->map.elem.no_img = NULL;
	cub3d->map.elem.so_img = NULL;
	cub3d->map.elem.we_img = NULL;
	cub3d->map.elem.ea_img = NULL;
	cub3d->map.elem.floor[0] = -1;
	cub3d->map.elem.floor[1] = -1;
	cub3d->map.elem.floor[2] = -1;
	cub3d->map.elem.cell[0] = -1;
	cub3d->map.elem.cell[1] = -1;
	cub3d->map.elem.cell[2] = -1;
	cub3d->map.elem.flag_floor = 0;
	cub3d->map.elem.flag_cell = 0;
}

int	char_is_space(char c)
{
	if (c >= 9 && c <= 11)
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

int		height_map(char **file)
{
	int		i;

	i = 0;
	while (file[i])
		i++;
	return (i);
}

int	malloc_map(char **file, t_cub3d *cub3d)
{
	size_t	nb_line;
	size_t	y;

	nb_line = height_map(file);
	cub3d->map.map = malloc(sizeof(char *) * (nb_line + 1));
	if (!cub3d->map.map)
		return (ft_putstr_fd(ERR_MALLOC, 2), 0);
	y = 0;
	while (y <= nb_line)
	{
		cub3d->map.map[y] = ft_strdup(file[y]);
		printf("%s\n", cub3d->map.map[y]);
		y++;
	}
	return (1); 
}	

int	generate_map(char **file, t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (!char_is_space(file[i][j]) && file[i][j] != '1')
			 	return (0);
			if (file[i][j] == '1')
				return (malloc_map(file + i, cub3d));
			j++;
		}
		i++;
	}
	return (0);
}

int check_file(t_cub3d *cub3d)
{
	int i;

	i = 0;
	init_elem_struct(cub3d);
	while (cub3d->file[i])
	{
		if (ft_isalpha(cub3d->file[i][0]) && cub3d->map.elem_nb != 6)
			if (!find_elem(cub3d->file[i], cub3d))
				return (1);
		if (cub3d->map.elem_nb == 6)
			return(i++, generate_map(cub3d->file + i, cub3d));
		i++;
	}
	return (1);
}
