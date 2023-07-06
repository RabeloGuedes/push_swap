/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 07:51:42 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 09:37:36 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_node *head)
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

void	sa(t_node *head_a)
{
	swap(head_a);
}

void	sb(t_node *head_b)
{
	swap(head_b);
}

void	ss(t_node *head_a, t_node *head_b)
{
	sa(head_a);
	sb(head_b);
}
