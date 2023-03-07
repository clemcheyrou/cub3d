/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:50:22 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/01/09 21:41:57 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	count_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (s && *s)
	{
		while (*s && is_charset(*s, c))
			s++;
		if (*s && !(is_charset(*s, c)))
		{
			count ++;
			while (*s && !(is_charset(*s, c)))
			s++;
		}
	}
	return (count);
}

static int	strlen_without_charset(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !(is_charset(s[i], c)))
		i++;
	return (i);
}

static char	*malloc_word(char const *s, char c)
{
	char	*str;
	int		len_word;
	int		i;

	i = 0;
	len_word = strlen_without_charset(s, c);
	str = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!str)
		return (NULL);
	while (s[i] && !(is_charset(s[i], c)))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;

	i = 0;
	strs = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!strs)
		return (NULL);
	while (s && *s)
	{
		while (*s && is_charset(*s, c))
			s++;
		if (*s && !(is_charset(*s, c)))
		{
			strs[i] = malloc_word(s, c);
			i++;
			while (*s && !(is_charset(*s, c)))
				s++;
		}
	}
	strs[i] = NULL;
	return (strs);
}
/*
int	main()
{
	char	*s;
	char	c;
	char **tab;
	int i;
	int j;

	s = " bonjour     toi";
	c = ' ';
	tab = ft_split(s, c);
	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		i++;
	}
}
*/
