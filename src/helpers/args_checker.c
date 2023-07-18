/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:17:16 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/18 10:15:59 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// This function checks if all arguments are valid by using
// other functions; are_arg_num, a_is_int_range and duplicates_checker.
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
