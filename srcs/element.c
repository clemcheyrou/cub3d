/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:49:22 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/09 16:27:29 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef int(*t_fp_pointer)();

typedef struct s_parse
{
	char			*str;
	int				len;
	int				type;
	t_fp_pointer	fp;
}	t_parse;

//if is alpha rentrer dans cette fct
int	parse_imgs(char *line, t_elem *elem, int type)
{
	line = ft_strtrim(line, " ");
	if (!line)
		return (ft_putstr_fd(ERR_DEF, 2), 0);
	printf("%s\n", elem->no_img);
	if (type == 1 && elem->no_img == NULL)
		return(elem->no_img = ft_strdup(line), 1);
	if (type == 2 && elem->so_img == NULL)
		return(elem->so_img = ft_strdup(line), 1);
	if (type == 3 && elem->we_img == NULL)
		return(elem->we_img = ft_strdup(line), 1);
	if (type == 4 && elem->ea_img == NULL)
		return(elem->ea_img = ft_strdup(line), 1);
	return (ft_putstr_fd(ERR_DBL, 2), 0); // + free
}

int	colors_tab(char *line, t_elem *elem, int type)
{
	char	**tab;
	int		i;

	tab = ft_split(line, ',');
	i = 0;
	if (!tab || tab[4] != NULL)
		return (ft_putstr_fd(ERR_DEF, 2), 0); // + free tab
	while (tab[i])
	{
		if (!ft_alldigit(tab[i]))
			return (0); // MESSAGE ERR + free tab plus tabi
		if (type == 4)
			elem->floor[i] = ft_atoi(tab[i]);
		if (type == 5)
			elem->cell[i] = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab); // plutot freedup()
	return (1);
}

int	parse_color(char *line, t_elem *elem, int type)
{
	line = ft_strtrim(line, " ");
	if (!line)
		return (ft_putstr_fd(ERR_DEF, 2), 0);
	if (type == 5 && elem->floor == 0) // ou NULL ?
		return(colors_tab(line, elem, type));
	if (type == 6 && elem->cell == 0)
		return(colors_tab(line, elem, type));
	return (ft_putstr_fd(ERR_DBL, 2), 0);
}

int	find_elem(char *line, t_map *map)
{
	int				i;
	const t_parse	storage [7] = {
	{"NO ", 3, 1, parse_imgs},
	{"SO ", 3, 2, parse_imgs},
	{"WE ", 3, 3, parse_imgs},
	{"EA ", 3, 4, parse_imgs},
	{"F ", 2, 5, parse_color},
	{"C ", 2, 6, parse_color},
	{NULL, 0, 0, NULL}
	};

	i = 0;
	ft_memset(&map->elem, sizeof(t_elem), 0);
	while (storage[i].str)
	{
		if (!ft_strncmp(line, storage[i].str, storage[i].len))
			return (storage[i].fp(line + storage[i].len, map->elem, storage[i].type)); //id existe, cependant regarder si doublon
		i++;
	}
	//free tout car id n'existe pas
	return (ft_putstr_fd("KO\n", 2), 0); ///
}



// int	parse_elem(char *line, int type, int len, t_map *map)
// {
// 	while (line[len])
// 	{
// 		while (is_space(line[len]))
// 			len++;
// 		if (line[len] == '\0')
// 			return (0); // + ERR
// 		if (type == 1)
// 			map.imgs->no_imgs = ft_strtrim(line + len, ' ');
// 		if (type == 2)
// 		if (type == 3)
// 		if (type == 4)
// 		if (type == 5)
// 		if (type == 6)
// 	}
// }

int check_file(t_cub3d *cub3d)
{
	int i;

	i = 0;
	while (cub3d->file[i])
	{
		if (ft_isalpha(cub3d->file[i][0]))
			if (!find_elem(cub3d->file[i], &cub3d->map))
				return (ft_putstr_fd(ERR_DEF, 2), 1);
				 //free_struct
		//if (ft_strchr(map[i], '1') && !(ft_strchr(map[i], 'F') || ft_strchr(map[i], 'C'))
		//		&& elem_nb != 6)
		//	return (ft_putstr_fd(ERR_DEF, 2), 1);	
		i++;
	}
	return (1);
}