/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:16:21 by adegain           #+#    #+#             */
/*   Updated: 2023/04/10 17:41:59 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_len_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	if (!tab[0] || !tab[1]
		|| !tab[2] || tab[3] != NULL)
		return (free_array(tab), free(tab), 0);
	return (1);
}

int	color_tab5(t_elem *elem, char **tab, int i)
{
	elem->floor[i] = ft_atoi(tab[i]);
	if (elem->floor[i] < 0 || elem->floor[i] > 255)
		return (0);
	elem->flag_floor++;
	return (1);
}

int	color_tab6(t_elem *elem, char **tab, int i)
{
	elem->cell[i] = ft_atoi(tab[i]);
	if (elem->cell[i] < 0 || elem->cell[i] > 255)
		return (0);
	elem->flag_cell++;
	return (1);
}

void	cut_malloc_map(char **file, t_cub3d *cub3d)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < cub3d->map.map_height)
	{
		if (y == 0 || y == (cub3d->map.map_height - 1))
			cub3d->map.map[y] = ft_strdup_x(cub3d);
		else
		{
			cub3d->map.map[y] = ft_strdupdup(cub3d, file[i]);
			if (!cub3d->map.map[y])
				cub3d->map.map[y] = ft_strdup_x(cub3d);
			i++;
		}
		y++;
	}
	cub3d->map.map[y] = NULL;
}
