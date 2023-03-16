/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:08:25 by adegain           #+#    #+#             */
/*   Updated: 2023/03/15 20:51:56 by ccheyrou         ###   ########.fr       */
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
				{
					printf("[%c]\n", cub3d->map.map[y][x]);
					return (ft_putstr_fd(ERR_MAP, 2), free_struct(cub3d), 0);
				}
			if (valid_char(cub3d->map.map[y][x], 2)) // check autour du plyr ? au moins 1 zero
			{
				cub3d->map.player_nb++;
				cub3d->map.direction = cub3d->map.map[y][x];
			}
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
		while(file[i][j])
		{
			if (file[i][j] != ' ' && !valid_char(file[i][j], 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_strdupxx(t_cub3d *cub3d)
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
		{
			cub3d->map.map[y] = ft_strdupxx(cub3d);
			printf("%s\n", cub3d->map.map[y]);
		}
		else
		{
			cub3d->map.map[y] = ft_strdupdup(cub3d, file[i]);
			if (!cub3d->map.map[y])
				cub3d->map.map[y] = ft_strdupxx(cub3d);
			printf("%s\n", cub3d->map.map[y]);
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
