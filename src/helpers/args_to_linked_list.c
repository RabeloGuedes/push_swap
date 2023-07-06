/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:26:28 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 09:37:22 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

t_node	*create_nodes(size_t nodes_amount)
{
	t_node	*head;
	t_node	*curr;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	curr = head;
	while (--nodes_amount)
	{
		if (!bind_nodes(curr, create_node()))
			return (NULL);
		curr = curr->next;
	}
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

t_node	*args_to_linked_list(char **args, size_t nodes_amount)
{
	t_node	*head;

	head = create_nodes(nodes_amount);
	if (!head)
		return (NULL);
	fill_nodes(head, args);
	return (head);
}
