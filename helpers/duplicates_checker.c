/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:05:23 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/05 14:49:44 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_duplicates_in_string(const char *str)
{
	const char	*save;

	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str)
		{
			save = str;
			while (*save)
			{
				while (*save && !ft_isspace(*save))
					save++;
				if (*save && ft_atoi(str) == ft_atoi(save))
					return (0);
				while (ft_isspace(*save))
					save++;
			}
		}
		while (*str && !ft_isspace(*str))
			str++;
	}
	return (1);
}

int	duplicates_checker(char **args)
{
	char	**save;
	char	*str;

	while (*args)
	{
		str = ft_strtrim(*args, " ");
		if (!check_duplicates_in_string(str))
		{
			free(str);
			return (0);
		}
		free(str);
		save = args + 1;
		while (*save)
		{
			if (ft_atoi(*args) == ft_atoi(*save))
				return (0);
			save++;
		}
		args++;
	}
	return (1);
}
