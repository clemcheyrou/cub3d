/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:37:50 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/12/16 13:02:47 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char letter, int flag)
{
	char	*new_s;
	char	s2[2];

	s2[0] = letter;
	s2[1] = '\0';
	if (!letter)
		return (s1);
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, ft_strlen(s1) + 1);
	ft_strlcat(new_s, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (flag == 1)
		free(s1);
	return (new_s);
}

char	*ft_strjoin_str(char *s1, char *s2, int flag)
{
	char	*new_s;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, ft_strlen(s1) + 1);
	ft_strlcat(new_s, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (flag == 1)
		free(s1);
	if (flag == 2)
		free(s2);
	return (new_s);
}
