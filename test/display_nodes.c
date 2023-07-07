/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:38:10 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/07 19:38:30 by arabelo-         ###   ########.fr       */
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
