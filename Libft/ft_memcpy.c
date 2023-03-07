/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:02:32 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/18 20:57:20 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

/*
int	main()
{
//TEST1
	char	dest[]="salut toi";
	char	src[]="ca va imotep";

	char	dest_test[]="salut toi";
	char	src_test[]="ca va imotep";
	
	size_t n = 5;
	ft_memcpy(dest, src, n);
	memcpy(dest_test, src_test, n);

	printf("%s\n", dest);
	printf("%s", dest_test);
}
*/
