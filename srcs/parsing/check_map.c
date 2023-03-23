/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:38:33 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/22 18:44:45 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_around(char **map, int x, int y)
{
	if (!valid_char(map[x][y - 1], 1))
		return (0);
	if (!valid_char(map[x][y + 1], 1))
		return (0);
	if (!valid_char(map[x - 1][y], 1))
		return (0);
	if (!valid_char(map[x + 1][y], 1))
		return (0);
	return (1);
}

int	check_around_plyr(char **map, int x, int y)
{
	int	zero;

	zero = 0;
	if (map[x][y - 1] == '0' || map[x][y + 1] == '0'
		|| map[x - 1][y] == '0' || map[x + 1][y] == '0')
		zero++;
	if (map[x][y - 1] == 'X' || map[x][y + 1] == 'X'
		|| map[x - 1][y] == 'X' || map[x + 1][y] == 'X')
		return (0);
	if (zero < 1)
		return (0);
	return (1);
}

void	save_plyr(t_cub3d *cub3d, int x, int y)
{
	cub3d->map.player_nb++;
	if (cub3d->map.map[x][y] == 'N')
		cub3d->map.direction = 0;
	if (cub3d->map.map[x][y] == 'S')
		cub3d->map.direction = 1;
	if (cub3d->map.map[x][y] == 'E')
		cub3d->map.direction = 2;
	if (cub3d->map.map[x][y] == 'W')
		cub3d->map.direction = 3;
	cub3d->ray.map_x = x;
	cub3d->ray.map_y = y;
	cub3d->ray.pos_x = x;
	cub3d->ray.pos_y = y;
}

int	check_map(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	while (cub3d->map.map[x])
	{
		y = 0;
		while (cub3d->map.map[x][y])
		{
			if (cub3d->map.map[x][y] == '0')
				if (!check_around(cub3d->map.map, x, y))
					return (ft_putstr_fd(ERR_MAP, 2), free_struct(cub3d), 0);
			if (valid_char(cub3d->map.map[x][y], 2))
				save_plyr(cub3d, x, y);
			y++;
		}
		x++;
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
