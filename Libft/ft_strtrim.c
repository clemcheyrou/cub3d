/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:00:39 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/14 14:05:57 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_set(char s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*new_s;
	int		len_s1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && is_set(s1[i], set))
		i++;
	len_s1 = ft_strlen(s1);
	while (i < len_s1 && is_set(s1[len_s1 - 1], set))
		len_s1--;
	if (len_s1 == 0)
		return (NULL);
	if (len_s1 == ft_strlen(s1))
		return (ft_strdup(s1));
	new_s = malloc(sizeof(char) * (len_s1 - i + 1));
	if (!new_s)
		return (NULL);
	while (i < len_s1)
		new_s[j++] = s1[i++];
	new_s[j] = '\0';
	return (new_s);
}
