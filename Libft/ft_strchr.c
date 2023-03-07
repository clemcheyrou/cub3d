/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:14:47 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/18 23:26:09 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	return (0);
}

/*
int	main()
{
	const char	s[] = "bonjour";
	const char	s1[] = "bonjour";
	int c = '\0';

	printf("%s\n", ft_strchr(s,c));
	printf("%s\n", strchr(s1,c));

	return 0;
}*/
