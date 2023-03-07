/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:19:55 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/06 18:16:18 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
int	main()
{
	const char s[] = "hello";
	const char s1[] = "hello";
	int c = 'l';
	size_t n = sizeof(char) * 4;

	printf("Chaine initial : %s\n", s);
	printf("Resultat trouve : %s\n", ft_memchr(s,c,n));
	printf("Resultat recherche : %s\n", memchr(s1,c,n));
}
*/
