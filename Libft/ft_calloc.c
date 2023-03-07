/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:44:15 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/18 17:49:26 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (size && (nmemb * size) / size != nmemb)
		return (NULL);
	str = (void *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size * nmemb);
	return ((void *)str);
}
