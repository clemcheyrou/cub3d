/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:19:38 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/13 17:55:38 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

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
