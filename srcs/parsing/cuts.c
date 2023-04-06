/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:16:21 by adegain           #+#    #+#             */
/*   Updated: 2023/04/06 12:33:43 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_tab5(t_elem *elem, char **tab, int i)
{
	elem->floor[i] = ft_atoi(tab[i]);
	elem->flag_floor++;
	if (elem->floor[i] < 0 || elem->floor[i] > 255)
		return (0);
	return (1);
}

int	color_tab6(t_elem *elem, char **tab, int i)
{
	elem->cell[i] = ft_atoi(tab[i]);
	elem->flag_cell++;
	if (elem->cell[i] < 0 || elem->cell[i] > 255)
		return (0);
	return (1);
}

void	cut_malloc_map(char **file, t_cub3d *cub3d)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (x < cub3d->map.map_height)
	{
		if (x == 0 || x == (cub3d->map.map_height - 1))
			cub3d->map.map[x] = ft_strdup_x(cub3d);
		else
		{
			cub3d->map.map[x] = ft_strdupdup(cub3d, file[i]);
			if (!cub3d->map.map[x])
				cub3d->map.map[x] = ft_strdup_x(cub3d);
			i++;
		}
		x++;
	}
	cub3d->map.map[x] = NULL;
}
