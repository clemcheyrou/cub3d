/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:32:42 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/07/18 21:33:39 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct t_list
{
	char			*val;
	struct t_list	*next;
}	t_list;

char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
void	free_before(t_list *stash);
char	*len_line(t_list *stash, char **line);
int		find_n(t_list *stash, t_list **last_link);

#endif
