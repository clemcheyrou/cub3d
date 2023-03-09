/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:19:06 by adegain           #+#    #+#             */
/*   Updated: 2023/03/09 14:09:10 by adegain          ###   ########.fr       */
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