/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:32:42 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/08 18:06:07 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct t_line
{
	char			*val;
	struct t_line	*next;
}	t_line;

char	*get_next_line(int fd);

size_t	ft_strlen2(char *str);
void	free_before(t_line *stash);
char	*len_line(t_line *stash, char **line);
int		find_n(t_line *stash, t_line **last_link);

#endif
