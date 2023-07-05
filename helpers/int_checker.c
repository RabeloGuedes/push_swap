/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:31:28 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/05 13:52:46 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	int_checker(const char *str)
{
	long long	nbr;
	int			i;

	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		nbr = ft_atoll(&str[i]);
		if (nbr < INT32_MIN || nbr > INT32_MAX)
			return (0);
		while (str[i] && !ft_isspace(str[i]))
			i++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str)
			&& *str != '\0' && *str != '-')
			return (0);
		str++;
	}
	return (1);
}
