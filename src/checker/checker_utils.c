/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:08:48 by arabelo-          #+#    #+#             */
/*   Updated: 2023/08/07 14:19:04 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	read_commands_check_order(t_list **head_a, t_list **head_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line || !movement_checker(line))
		{
			free(line);
			break ;
		}
		movement_applier(line, head_a, head_b);
		free(line);
	}
	if (!ft_lstsize(*head_b) && is_ordered(*head_a, &is_ascending))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
