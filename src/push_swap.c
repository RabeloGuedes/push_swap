/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:11:35 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 13:24:28 by arabelo-         ###   ########.fr       */
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

void	display_nodes(t_stack *stack)
{
	t_node	*head;
	t_node	*curr;

	head = *(stack->head);
	curr = head;
	ft_printf("[\n");
	while (curr)
	{
		display_node_infos(curr);
		curr = curr->next;
		head = curr;
	}
	// display_node_infos(curr);
	ft_printf("]\n");
}

// void	display_swap(t_node	*head)
// {
// 	ft_printf("Before Swap A:\n");
// 	display_nodes(head);
// 	sa(head);
// 	ft_printf("After Swap A:\n");
// 	display_nodes(head);
// }

// void	display_push(t_node *head_a, t_node *head_b)
// {
// 	ft_printf("Before Push A:\n");
// 	display_nodes(head_a);
// 	// ft_printf("Before Push B:\n");
// 	// display_nodes(head_b);
// 	pa(head_a, head_b);
// 	ft_printf("After Push A:\n");
// 	display_nodes(head_a);
// 	ft_printf("After Push B:\n");
// 	display_nodes(head_b);
// }

// void	test_push(char **args, size_t nodes_amount)
// {
// 	t_node	*head_a;
// 	t_node	*head_b;

// 	head_a = args_to_linked_list(args, nodes_amount);
// 	head_b = args_to_linked_list(args, nodes_amount);
// 	if (!head_a || !head_b)
// 			return ;
// 	display_push(head_a, head_b);
// 	free_nodes(head_a);
// 	free_nodes(head_b);
// }

int	bind_nodes(t_node *prev_node, t_node *new_node)
{
	if (!prev_node || !new_node || prev_node == new_node)
		return (0);
	prev_node->next = new_node;
	new_node->prev = prev_node;
	return (1);
}

t_node	*create_node(void)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	return (new_node);
}

t_node	*create_nodes(size_t nodes_amount, t_stack *stack)
{
	t_node	*head;
	t_node	*curr;

	head = create_node();
	if (!head)
		return (NULL);
	curr = head;
	stack->head = &head;
	ft_printf("Hello\n");
	while (--nodes_amount)
	{
		if (!bind_nodes(curr, create_node()))
			return (NULL);
		curr = curr->next;
	}
	stack->tail = &curr;
	return (head);
}

void	fill_nodes(t_node *head, char **args)
{
	while (*args)
	{
		head->data = ft_atoi(*args++);
		head = head->next;
	}
}

void	args_to_linked_list(char **args, size_t nodes_amount, t_stack *stack)
{
	t_node	*head;

	head = create_nodes(nodes_amount, stack);
	if (!head)
		return ;
	fill_nodes(head, args);
}


t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	// t_stack	*stack_b;

	if (ac > 1)
	{
		if (!args_checker(++av))
			return (0);
		stack_a = create_stack();
		args_to_linked_list(av, ac - 1, stack_a);
		// args_to_linked_list(av, ac - 1, stack_b);
		if (!stack_a)
			return (0);
		display_nodes(stack_a);
		// display_swap(stack_a);
		// test_push(av, ac - 1);
	}
	return (0);
}
