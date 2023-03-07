/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:16:45 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/12 17:35:45 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}

/*
int main()
{
	char s28[]="12345";
	char s29[]="12345";

	ft_bzero(s28, 1);
	bzero(s29, 1);
	printf("ft_bzero : %s\n", s28);
	printf("bzero : %s\n", s29);
}
*/
