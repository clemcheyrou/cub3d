/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:23:09 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/18 17:56:20 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	find_len(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	a;
	long	i;

	a = n;
	i = find_len(a);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (a < 0)
	{
		str[0] = '-';
		a *= -1;
	}
	if (a == 0)
		str[0] = '0';
	while (a > 0)
	{
		str[i] = (a % 10) + '0';
		a /= 10;
		i--;
	}
	return (str);
}
/*
#include <stdio.h>

int	main()
{
	int	n = 5;
	printf("%s", ft_itoa(n));
}*/
