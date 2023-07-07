/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:26:03 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/07 11:29:10 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	display_node_infos(t_list *node)
{
	ft_printf("	{\n		data: %i,\n", *(int *)(node->content));
	ft_printf("		next: %p,\n", node->next);
	ft_printf("		address: %p\n", node);
	ft_printf("	},\n");
}

void	display_nodes(t_list *stack)
{
	ft_printf("[\n");
	while (stack)
	{
		display_node_infos(stack);
		stack = stack->next;
	}
	ft_printf("]\n");
}

void	display_swap(t_list	**head)
{
	ft_printf("Before Swap A:\n");
	display_nodes(*head);
	swap(head, 'a');
	ft_printf("After Swap A:\n");
	display_nodes(*head);
}

void	display_push(t_list **head_a, t_list **head_b)
{
	ft_printf("Before Push A:\n");
	display_nodes(*head_a);
	ft_printf("Before Push B:\n");
	display_nodes(*head_b);
	push(head_a, head_b, 'a');
	ft_printf("After Push A:\n");
	display_nodes(*head_a);
	ft_printf("After Push B:\n");
	display_nodes(*head_b);
}
