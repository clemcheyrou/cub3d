/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:34:55 by adegain           #+#    #+#             */
/*   Updated: 2023/03/09 16:02:36 by adegain          ###   ########.fr       */
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
		return (ft_putstr_fd(ERR_RD, 2), 0);
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

char	**remove_nl(char **file)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] == '\n')
				file[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (file);
}

char	**get_file(char *av, t_cub3d *cub3d)
{
	size_t	y;
	size_t	nb_line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	nb_line = ft_nb_line(av);
	cub3d->file = malloc(sizeof(char *) * (nb_line + 1));
	if (!cub3d->file)
		return (NULL);
	y = 0;
	while (y <= nb_line)
	{
		cub3d->file[y] = get_next_line(fd);
		y++;
	}
	close(fd);
	if (!cub3d->file)
		return (NULL);
	return (remove_nl(cub3d->file)); // le faire plus tard ?
}
