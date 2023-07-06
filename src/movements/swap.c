/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 07:51:42 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 20:43:09 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_list **stack, char swap_type)
{
	t_list	*first;
	t_list	*second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
		first->next = second->next;
		second->next = first;

		*stack = second;
	}
	if (swap_type == 'a')
		ft_printf("sa\n");
	else if (swap_type == 'b')
		ft_printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b, char swap_type)
{
	swap(&stack_a, swap_type);
	swap(&stack_b, swap_type);
	ft_printf("ss\n");
}
