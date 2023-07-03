/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:11:35 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/03 14:20:59 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		while ((++av, *av))
		{
			if (!int_checker(*av))
				ft_printf("ops, some intput is not a interger\n");
			else
				ft_printf("it seems that everthing is correct\n");
		}	
	}
	return (0);
}
