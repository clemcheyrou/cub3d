/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:41:35 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/01/14 20:44:51 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (2);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int	main()
{
//TEST1
	const char s1[]= "hello toi";
	const char s2[]= "yolo";
	size_t n = 8;

	printf("%d\n",ft_strcmp(s1, s2, n));
	return 0;
}*/
