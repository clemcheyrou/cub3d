/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:53:12 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/18 20:45:53 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] && len >= ft_strlen(little))
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
		len--;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main()
{
	const char s1[] = "cococorio";
	const char s2[] = "cocorico";
	size_t len = 8;

	printf("%s\n", ft_strnstr(s2, s1,len));
	return  0;
}
*/
