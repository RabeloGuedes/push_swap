/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:31:12 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/10 14:11:56 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_ascending(int a, int b)
{
	return (a <= b);
}

int	is_ordered(t_list **head, int (*cmp)(int, int))
{
	if (!head || !*head)
		return (0);
	while ((*head)->next)
	{
		if (!(cmp(*(int *)(*head)->content, *(int *)(*head)->next->content)))
			return (0);
		*head = (*head)->next;
	}
	return (1);
}
