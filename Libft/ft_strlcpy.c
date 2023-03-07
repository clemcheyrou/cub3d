/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:52:20 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/01/13 20:11:03 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{	
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char	*dest;
	const char	*source;
	size_t	i;

	//char	*dest_test;
	//const char	*source_test;
	//size_t	i_test;

	dest = "hello";
	source = "yolo";
	i = 3;

	//dest_test = "hello";
	//source_test = "yolo";
	//i_test = 5;

	printf("TEST 1 : %ld", ft_strlcpy(dest, source, i));
	//printf("\nVerif TEST 1 : %d", strlcpy(dest_test, source_test, i_test));

	return(0);
} 
*/
