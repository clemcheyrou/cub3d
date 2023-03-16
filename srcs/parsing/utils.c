/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:02:52 by adegain           #+#    #+#             */
/*   Updated: 2023/03/15 20:52:29 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_char(char c, int flag)
{
	int		i;
	char	*s;

	i = 0;
	if (flag == 1)
		s = MAP_CHAR;
	else
		s = MAP_PLYR;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
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
	return (i + 2);
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
	return (cub3d->map.map_length);
}

char	*ft_strdupdup(t_cub3d *cub3d, char *s)
{
	char	*new_s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s[0] == '\0')
		return (NULL);
	new_s = (char *)malloc(sizeof(char) * (cub3d->map.map_length + 3));
	if (!new_s)
		return (NULL);
	new_s[j++] = 'X';
	while (j <= cub3d->map.map_length)
	{
		if (i >= ft_strlen(s) || s[i] == ' ')
		{
			new_s[j++] = 'X';
			i++;
		}
		else
			new_s[j++] = s[i++];
	}
	new_s[j] = '\0';
	return (new_s);
}
