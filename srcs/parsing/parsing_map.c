/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:08:25 by adegain           #+#    #+#             */
/*   Updated: 2023/03/20 12:39:57 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup_x(t_cub3d *cub3d)
{
	char	*new_s;
	int		i;

	i = 0;
	cub3d->map.map_length = check_length_map(cub3d);
	new_s = (char *)malloc(sizeof(char) * (cub3d->map.map_length + 3));
	if (!new_s)
		return (NULL);
	while (i <= cub3d->map.map_length)
	{
		new_s[i] = 'X';
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

int	malloc_map(char **file, t_cub3d *cub3d)
{
	int	y;
	int	i;

	cub3d->map.map_height = height_map(file);
	cub3d->map.map_length = check_length_map(cub3d);
	if (!valid_file(file))
		return (ft_putstr_fd(ERR_MAP, 2), free_struct(cub3d), 0);
	cub3d->map.map = malloc(sizeof(char *) * (cub3d->map.map_height + 1));
	if (!cub3d->map.map)
		return (ft_putstr_fd(ERR_MALLOC, 2), 0);
	y = 0;
	i = 0;
	while (y < cub3d->map.map_height)
	{
		if (y == 0 || y == (cub3d->map.map_height - 1))
			cub3d->map.map[y] = ft_strdup_x(cub3d);
		else
		{
			cub3d->map.map[y] = ft_strdupdup(cub3d, file[i]);
			if (!cub3d->map.map[y])
				cub3d->map.map[y] = ft_strdup_x(cub3d);
			i++;
		}
		y++;
	}
	cub3d->map.map[y] = NULL;
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
