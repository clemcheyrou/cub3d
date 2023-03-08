/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegain <adegain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:42:54 by adegain           #+#    #+#             */
/*   Updated: 2023/03/08 18:02:28 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hello(int i)
{
	return (i);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (!envp)
		return (ft_putstr_fd(ERR_ENV, 2), 0);
	hello(15);
	if (argc == 1)
		return (ft_putstr_fd("OK", 1), 1);
}
