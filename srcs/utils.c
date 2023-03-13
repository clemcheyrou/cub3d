/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:02:52 by adegain           #+#    #+#             */
/*   Updated: 2023/03/13 16:23:53 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	char_is_space(char c)
{
	if (c >= 9 && c <= 11)
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

int	height_map(char **file)
{
	int		i;

	i = 0;
	while (file[i])
		i++;
	return (i);
}

int	check_length_map(t_cub3d *cub3d)
{
	int	y;
	int	x;

	y = 0;
	cub3d->map.map_length = 0;
	while (cub3d->file[y])
	{
		x = 0;
		while (cub3d->file[y][x])
			x++;
		if (x > cub3d->map.map_length)
			cub3d->map.map_length = x;
		y++;
	}
	return (cub3d->map.map_length + 2);
}

char	*ft_strdupdup(t_cub3d *cub3d, char *s)
{
	char	*new_s;
	size_t	len;
	size_t	i;

	i = 0;
	len = check_length_map(cub3d);
	new_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (NULL);
	while (i < len)
	{
		if (i == 0 || i == len || s[i] == ' ' || s[i] == '\0')
			new_s[i] = 'X';
		else
			new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
