/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:32:25 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/01/09 22:46:07 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi(const char *nptr)
{
	int			i;
	long long	res;
	int			neg;

	neg = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * neg);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main ()
{
	const char *c;
	c = "   -456";
	printf("%d", ft_atoi(c));
	printf("%d", atoi(c));
}
*/	
