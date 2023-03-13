/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:18:56 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/13 16:26:25 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_alldigit(char *str)
{
	if (!str)
		return (0);
	while (str && *str)
	{
		if (!(*str >= '0' || *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}
