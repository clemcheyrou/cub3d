/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:00:39 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/12/11 22:35:21 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	size_t	len_s1;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && is_set(s1[i], set))
		i++;
	len_s1 = ft_strlen(s1);
	while (i < len_s1 && is_set(s1[len_s1 - 1], set))
		len_s1--;
	new_s = malloc(sizeof(char) * (len_s1 - i + 1));
	if (!new_s)
		return (NULL);
	while (i < len_s1)
		new_s[j++] = s1[i++];
	new_s[j] = '\0';
	free(s1);
	return (new_s);
}
/*
#include <stdio.h>

int	main()
{
	char const s1[] = "   xxxtripouillexx ";
	char const s2[] = " x";
	
	printf("%s\n", ft_strtrim(s1, s2));
}*/
