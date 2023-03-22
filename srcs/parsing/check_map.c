/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:38:33 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/22 15:50:32 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_around(char **map, int y, int x)
{
	if (!valid_char(map[y][x - 1], 1))
		return (0);
	if (!valid_char(map[y][x + 1], 1))
		return (0);
	if (!valid_char(map[y - 1][x], 1))
		return (0);
	if (!valid_char(map[y + 1][x], 1))
		return (0);
	return (1);
}

int	check_around_plyr(char **map, int y, int x)
{
	int	zero;

	zero = 0;
	if (map[y][x - 1] == '0' || map[y][x + 1] == '0'
		|| map[y - 1][x] == '0' || map[y + 1][x] == '0')
		zero++;
	if (map[y][x - 1] == 'X' || map[y][x + 1] == 'X'
		|| map[y - 1][x] == 'X' || map[y + 1][x] == 'X')
		return (0);
	if (zero < 1)
		return (0);
	return (1);
}

void	save_plyr(t_cub3d *cub3d, int y, int x)
{
	cub3d->map.player_nb++;
	if (cub3d->map.map[y][x] == 'N')
		cub3d->map.direction = 0;
	if (cub3d->map.map[y][x] == 'S')
		cub3d->map.direction = 1;
	if (cub3d->map.map[y][x] == 'E')
		cub3d->map.direction = 2;
	if (cub3d->map.map[y][x] == 'W')
		cub3d->map.direction = 3;
	cub3d->x = y;
	cub3d->y = x;
}

int	check_map(t_cub3d *cub3d)
{
	int	y;
	int	x;

	y = 0;
	while (cub3d->map.map[y])
	{
		x = 0;
		while (cub3d->map.map[y][x])
		{
			if (cub3d->map.map[y][x] == '0')
				if (!check_around(cub3d->map.map, y, x))
					return (ft_putstr_fd(ERR_MAP, 2), free_struct(cub3d), 0);
			if (valid_char(cub3d->map.map[y][x], 2))
				save_plyr(cub3d, y, x);
			x++;
		}
		y++;
	}
	if (cub3d->map.player_nb != 1)
		return (ft_putstr_fd(ERR_MAP, 2), free_struct(cub3d), 0);
	return (1);
}

int	valid_file(char **file)
{
	int		i;
	int		j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] != ' ' && !valid_char(file[i][j], 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}