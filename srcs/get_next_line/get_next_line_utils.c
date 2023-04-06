/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:01:23 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/06 15:26:28 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	free_before(t_line *stash)
{
	t_line	*tmp;
	t_line	*next;

	tmp = stash;
	while (tmp)
	{
		free(tmp->val);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

char	*len_line(t_line *stash, char **line)
{
	t_line	*element;
	int		i;
	int		len;

	len = 0;
	element = stash;
	if (!element)
		return (0);
	while (element)
	{
		i = 0;
		while (element->val[i])
		{
			if (element->val[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		element = element->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	return (*line);
}

int	find_n(t_line *stash, t_line **last_link)
{
	int		i;
	t_line	*last;

	i = 0;
	if (!stash)
		return (0);
	last = *last_link;
	while (last->val[i])
	{
		if (last->val[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
