/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:43:55 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/08 18:23:28 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_line	*clean_stash(t_line **stash, t_line **last_link)
{
	t_line	*last;
	t_line	*new_start;
	int		i;
	int		j;

	new_start = malloc(sizeof(t_line));
	if (stash == NULL || new_start == NULL)
		return (NULL);
	new_start->next = NULL;
	last = *last_link;
	i = 0;
	while (last->val[i] && last->val[i] != '\n')
		i++;
	if (last->val && last->val[i] == '\n')
		i++;
	new_start->val = malloc(sizeof(char) * ((ft_strlen2(last->val) - i) + 1));
	if (new_start->val == NULL)
		return (NULL);
	j = 0;
	while (last->val[i])
		new_start->val[j++] = last->val[i++];
	new_start->val[j] = '\0';
	free_before(*stash);
	*stash = new_start;
	return (*stash);
}

static char	*return_line(t_line *stash)
{
	char	*line;
	int		j;
	int		i;

	j = 0;
	len_line(stash, &line);
	if (line == NULL)
		return (NULL);
	while (stash)
	{
		i = 0;
		while (stash->val[i])
		{
			if (stash->val[i] == '\n')
			{
				line[j++] = stash->val[i];
				break ;
			}
			line[j++] = stash->val[i++];
		}
		stash = stash->next;
	}
	line[j] = '\0';
	return (line);
}

static void	add_to_stash(t_line **stash, char *buf, t_line **last_link)
{
	t_line	*new_element;
	t_line	*tmp;

	new_element = malloc(sizeof(t_line));
	if (new_element == NULL)
		return ;
	new_element->val = buf;
	new_element->next = NULL;
	if (*stash == NULL)
	{
		*stash = new_element;
		*last_link = new_element;
		return ;
	}
	tmp = *last_link;
	*last_link = new_element;
	tmp->next = new_element;
}

static void	fd_into_buf(t_line **stash, int fd, t_line **last_link)
{	
	char	*buf;
	int		ret;

	ret = 1;
	while (ret != 0 && !find_n(*stash, last_link))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret == 0 && *stash == NULL) || ret == -1)
		{
			free(buf);
			return ;
		}
		buf[ret] = '\0';
		add_to_stash(stash, buf, last_link);
	}
}

char	*get_next_line(int fd)
{
	static t_line		*stash = NULL;
	t_line				*last_link;
	char				*line;

	last_link = stash;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_into_buf(&stash, fd, &last_link);
	if (stash == NULL)
		return (NULL);
	line = return_line(stash);
	clean_stash(&stash, &last_link);
	if (line[0] == '\0')
	{
		free_before(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
