/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:55:56 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/18 18:09:31 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_new;
	unsigned char	*dest_new;

	src_new = (unsigned char *)dest;
	dest_new = (unsigned char *)src;
	if (src_new < dest_new)
	{
		while (n-- > 0)
			*src_new++ = *dest_new++;
	}
	else
	{
		while (n-- > 0)
			src_new[n] = dest_new[n];
	}
	return (dest);
}

/*
int	main()
{
	char src[] = "hello";
	char dest[] = "yoghjhgjhlo";

	char src1[] = "hello";
	char dest1[] = "yoghjhgjhlo";

	ft_memmove(dest,src,sizeof(char)*2);
	memmove(dest1, src1, sizeof(char)*2);
	
	printf("%s\n", dest);
	printf("%s\n", dest1);

	return 0;
}
*/
