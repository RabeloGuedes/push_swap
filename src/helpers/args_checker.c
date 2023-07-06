/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:17:16 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 07:48:47 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	args_checker(char **args)
{
	int	i;

	i = 0;
	
	while (args[i])
	{
		if (!are_arg_num(args[i]) || !a_is_int_range(args[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	if (!duplicates_checker(args))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}