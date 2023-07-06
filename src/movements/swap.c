/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 07:51:42 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 08:03:34 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(Node *head)
{
	int	temp;

	if (!head)
		return ;
	if (head->next)
	{
		temp = head->data;
		head->data = head->next->data;
		head->next->data = temp;
	}
}

void	sa(Node *head_a)
{
	swap(head_a);
}

void	sb(Node *head_b)
{
	swap(head_b);
}

void	ss(Node *head_a, Node *head_b)
{
	sa(head_a);
	sb(head_b);
}