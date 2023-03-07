/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:19:38 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/12/05 21:34:23 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	const char *c;
	c = "TEST1";
	printf("TEST1: %ld", ft_strlen(c));
	printf("\nVerif TEST1: %ld", strlen(c));
}
*/
