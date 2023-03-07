/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:29:31 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/12 14:16:43 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/* 
int	main()
{
	printf("ft_isalnum :\n");
	printf("5 : %d\n", ft_isalnum('5'));//FT_ISALNUM
	printf("* : %d\n", ft_isalnum('*'));//FT_ISALNUM
	printf("\n");
	printf("isalnum\n");
	printf("5 : %d\n", isalnum('5'));
	printf("* : %d\n", isalnum('*'));
}*/
