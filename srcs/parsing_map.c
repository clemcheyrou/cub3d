/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:08:25 by adegain           #+#    #+#             */
/*   Updated: 2023/03/13 16:20:07 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_char(char c)
{
	int	i;

	i = 0;
	while (MAP_CHAR[i])
	{
		if (c == MAP_CHAR[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_around(char **map, int y, int x)
{
	if (!valid_char(map[y][x - 1]))
		return (0);
	if (!valid_char(map[y][x + 1]))
		return (0);
	if (!valid_char(map[y - 1][x]))
		return (0);
	if (!valid_char(map[y + 1][x]))
		return (0);
	return (1);
}

int	check_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '0')
			{
				if (!check_around(map->map, y, x))
					return (ft_putstr_fd(ERR_MAP, 2), 0); // + freestruct ?
			}
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
				|| map->map[y][x] == 'E' || map->map[y][x] == 'W')
				map->player_nb++;
			x++;
		}
		y++;
	}
	if (map->player_nb != 1)
		return (ft_putstr_fd(ERR_MAP, 2), 0); // + freestruct
	return (1);
}

int	malloc_map(char **file, t_cub3d *cub3d)
{
	int	y;

	cub3d->map.map_height = height_map(file);
	cub3d->map.map = malloc(sizeof(char *) * (cub3d->map.map_height + 1));
	if (!cub3d->map.map)
		return (ft_putstr_fd(ERR_MALLOC, 2), 0);
	y = 0;
	while (y < cub3d->map.map_height)
	{
		cub3d->map.map[y] = ft_strdupdup(cub3d, file[y]);
		printf("[%s]\n", cub3d->map.map[y]);
		y++;
	}
	cub3d->map.map[y] = '\0';
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
