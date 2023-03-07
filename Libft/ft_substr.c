/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:30:18 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/18 23:46:44 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= len && start < ft_strlen(s))
		len = ft_strlen(s + start);
	if (start > ft_strlen(s))
		len = 0;
	new_s = malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (NULL);
	if (start <= ft_strlen(s))
	{
		while (s[start] != '\0' && i < len)
			new_s[i++] = s[start++];
	}
	new_s[i] = '\0';
	return (new_s);
}

/*
#include <stdio.h>
int main ()
{
  	char *s;

 	s = ft_substr("0123456789",9 , 10);
 	printf("%s\n", s);
}*/
