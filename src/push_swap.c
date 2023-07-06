/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:11:35 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 21:14:01 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	display_node_infos(t_list *node)
{
	// ft_printf("	{\n		data: %i,\n", *(int *)(node->content));
	ft_printf("		next: %p,\n", node->next);
	ft_printf("		address: %p\n", node);
	ft_printf("	},\n");
}

void	free_nodes(t_list *head)
{
	t_list	*curr;

	curr = head;
	while (curr)
	{
		curr = curr->next;
		free(head->content);
		free(head);
		head = curr;
	}
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

void	display_swap(t_list	*head)
{
	ft_printf("Before Swap A:\n");
	ft_printf("%p\n", head);
	display_nodes(head);
	swap(&head, 'a');
	ft_printf("%p\n", head);
	ft_printf("After Swap A:\n");
	display_nodes(head);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;

	if (ac > 1)
	{
		if (!args_checker(++av))
			return (0);
		stack_a = create_nodes(av);
		if (!stack_a)
			return (0);
		// display_nodes(stack_a);
		display_swap(stack_a);
		free_nodes(stack_a);
		// test_push(av, ac - 1);
	}
	return (0);
}
