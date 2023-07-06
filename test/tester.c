/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:58:07 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 10:56:53 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	display_node_infos(t_node *node)
{
	ft_printf("	{\n		data: %i,\n", node->data);
	ft_printf("		next: %p,\n", node->next);
	ft_printf("		prev: %p,\n", node->prev);
	ft_printf("		address: %p\n", node);
	ft_printf("	},\n");
}

void	free_nodes(t_node *head)
{
	t_node	*curr;

	curr = head;
	while (curr)
	{
		curr = curr->next;
		free(head);
		head = curr;
	}
}

void	display_nodes(t_node *head)
{
	t_node	*curr;

	curr = head;
	ft_printf("[\n");
	while (curr->next)
	{
		display_node_infos(curr);
		curr = curr->next;
		head = curr;
	}
	display_node_infos(curr);
	ft_printf("]\n");
}

void	display_swap(t_node	*head)
{
	ft_printf("Before Swap A:\n");
	display_nodes(head);
	sa(head);
	ft_printf("After Swap A:\n");
	display_nodes(head);
}

void	display_push(t_node *head_a, t_node *head_b)
{
	ft_printf("Before Push A:\n");
	display_nodes(head_a);
	ft_printf("Before Push B:\n");
	display_nodes(head_b);
	pa(head_a, head_b);
	ft_printf("After Push A:\n");
	display_nodes(head_a);
	ft_printf("After Push B:\n");
	display_nodes(head_b);
}

void	test_push(char **args, size_t nodes_amount)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = args_to_linked_list(nodes_amount, args);
	head_b = args_to_linked_list(nodes_amount, args);
	if (!head_a || !head_b)
			return ;
	display_push(head_a, head_b);
	free_nodes(head_a);
	free_nodes(head_b);
}

int	main(int ac, char **av)
{
	t_node	*head;

	if (ac > 1)
	{
		if (!args_checker(++av))
			return (0);
		head = args_to_linked_list(av, ac - 1);
		if (!head)
			return (0);
		display_nodes(head);
		display_swap(head);
		test_push(av, ac - 1);
	}
	return (0);
}
