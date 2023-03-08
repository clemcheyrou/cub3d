/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:01:23 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/06/11 16:29:10 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	free_before(t_list *stash)
{
	t_list	*tmp;
	t_list	*next;

	tmp = stash;
	while (tmp)
	{
		free(tmp->val);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

char	*len_line(t_list *stash, char **line)
{
	t_list	*element;
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
	*line = malloc(sizeof(char) * len + 1);
	return (*line);
}

int	find_n(t_list *stash, t_list **last_link)
{
	int		i;
	t_list	*last;

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
