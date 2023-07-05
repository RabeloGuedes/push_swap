/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:26:28 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/05 17:48:11 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

Node	*create_nodes(size_t nodes_amount)
{
	Node	*head;
	Node	*curr;

	head = (Node *)malloc(sizeof(Node));
	if (!head)
		return (NULL);
	head->is_first = 1;
	head->is_last = 0;
	curr = head;
	while (--nodes_amount)
	{
			curr->next = (Node *)malloc(sizeof(Node));
			if (!curr->next)
				return (NULL);
			curr->next->prev = curr;
			curr = curr->next;
			curr->is_first = 0;
			curr->is_last = 0;
	}
	curr->is_first = 0;
	curr->is_last = 1;
	curr->next = head;
	head->prev = curr;
	return (head);
}

void	fill_nodes(Node *head, char **args)
{
	while (*args)
	{
		head->data = ft_atoi(*args++);
		head = head->next;
	}
}

Node	*args_to_linked_list(char **args, size_t nodes_amount)
{
	Node	*head;

	head = create_nodes(nodes_amount);
	if (!head)
		return (NULL);
	fill_nodes(head, args);
	return (head);
}
