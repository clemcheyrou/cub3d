/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 22:14:06 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/12 21:55:59 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)(s + len));
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}

/*
int	main()
{
	const char	s[]="salutlut";
	const char	s1[]="salutlut";
	int c = 'u';

	printf("%s\n", ft_strrchr(s,c));
	printf("%s\n", strrchr(s1,c));
	return 0;
}
*/
