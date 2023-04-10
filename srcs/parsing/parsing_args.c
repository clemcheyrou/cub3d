/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:06:16 by adegain           #+#    #+#             */
/*   Updated: 2023/04/10 17:21:57 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	cub3d->map.line = ft_strtrim(line, " ");
	if (!cub3d->map.line)
		return (ft_putstr_fd(ERR_DEF, 2), 0);
	if (!check_img_param(cub3d->map.line))
		return (ft_putstr_fd(ERR_FIL, 2), 0);
	if (type == 1 && cub3d->map.elem.no_img == NULL)
		return (cub3d->map.elem_nb++, \
			cub3d->map.elem.no_img = ft_strdup(cub3d->map.line), 1);
	if (type == 2 && cub3d->map.elem.so_img == NULL)
		return (cub3d->map.elem_nb++, \
			cub3d->map.elem.so_img = ft_strdup(cub3d->map.line), 1);
	if (type == 3 && cub3d->map.elem.we_img == NULL)
		return (cub3d->map.elem_nb++, \
			cub3d->map.elem.we_img = ft_strdup(cub3d->map.line), 1);
	if (type == 4 && cub3d->map.elem.ea_img == NULL)
		return (cub3d->map.elem_nb++, \
			cub3d->map.elem.ea_img = ft_strdup(cub3d->map.line), 1);
	return (ft_putstr_fd(ERR_DBL, 2), 0);
}

int	colors_tab(char *line, t_elem *elem, int type)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(line, ',');
	if (!check_len_tab(tab))
		return (0);
	while (tab[i])
	{
		if (ft_alldigit(tab[i]))
			return (free_array(tab), free(tab), \
			ft_putstr_fd(ERR_CLR, 2), 0);
		if (type == 5)
			if (!color_tab5(elem, tab, i))
				return (free_array(tab), free(tab), \
				ft_putstr_fd(ERR_CLR, 2), 0);
		if (type == 6)
			if (!color_tab6(elem, tab, i))
				return (free_array(tab), free(tab), \
				ft_putstr_fd(ERR_CLR, 2), 0);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

int	check_color_param(char *line)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < ft_strlen(line))
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
		return (0);
	if (cub3d->map.elem.flag_cell > 3 || cub3d->map.elem.flag_floor > 3)
		return (ft_putstr_fd(ERR_DBL, 2), 0);
	return (cub3d->map.elem_nb++, 1);
}
