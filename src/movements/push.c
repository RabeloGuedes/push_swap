/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 08:21:25 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 13:06:53 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push(t_node *dest_top, t_node *origin_top)
{
	if (!origin_top)
		return ;
	if (!dest_top)
	{
		dest_top = origin_top;
		origin_top->next->prev = NULL;
	}
	else if (!origin_top->next && !origin_top->prev)
	{
		origin_top->next = dest_top;
		dest_top->prev = origin_top;
	}
	else
	{
		origin_top->next->prev = NULL;
		dest_top->prev = origin_top;
		origin_top->next = dest_top;
	}
}

void	pa(t_node *head_a, t_node *head_b)
{
	push(head_a, head_b);
}

void	pb(t_node *head_b, t_node *head_a)
{
	push(head_b, head_a);
}
