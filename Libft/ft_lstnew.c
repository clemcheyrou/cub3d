/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:14:45 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/12/13 16:26:29 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, int type)
{
	t_list	*element;

	element = malloc(sizeof(element));
	if (!element)
		return (NULL);
	element->content = content;
	element->type = type;
	element->next = NULL;
	return (element);
}
