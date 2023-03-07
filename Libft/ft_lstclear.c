/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:41:42 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/19 15:16:49 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*prochain_a_supp;

	if (!lst)
		return ;
	while (*lst)
	{
		prochain_a_supp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = prochain_a_supp;
	}
}
