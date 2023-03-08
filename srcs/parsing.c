/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:34:55 by adegain           #+#    #+#             */
/*   Updated: 2023/03/08 18:32:45 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_cub(char *av)
{
	size_t	len_max;
	size_t	len_min;
	char	*str;

	len_max = ft_strlen(av);
	len_min = len_max - 4;
	str = ".cub";
	while (len_min < len_max)
	{
		if (av[len_min] != *str)
			return (0);
		len_min++;
		str++;
	}
	return (1);
}

size_t	ft_nb_line(char *av)
{
	size_t	nb_line;
	char	*str;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	str = get_next_line(fd);
	nb_line = 0;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		nb_line++;
	}
	close(fd);
	return (nb_line);
}

char	**remove_nl(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (map);
}

char	**get_map(char *av)
{
	char	**map;
	size_t	x;
	size_t	nb_line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	nb_line = ft_nb_line(av);
	map = malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
		return (NULL);
	x = 0;
	while (x <= nb_line)
	{
		map[x] = get_next_line(fd);
		x++;
	}
	close(fd);
	if (!map)
		return (NULL);
	return (remove_nl(map));
}
