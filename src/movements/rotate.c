/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:14:06 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/07 19:37:18 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate(t_list **head, char rotate_type)
{
	t_list	*temp;

	if (!head || !*head)
		return ;
	temp = *head;
	while ((*head)->next)
	{
		*head = (*head)->next;
	}
	(*head)->next = temp;
	*head = temp->next;
	temp->next = NULL;
	if (rotate_type == 'a')
		ft_printf("ra\n");
	if (rotate_type == 'b')
		ft_printf("rb\n");
}

void	rr(t_list **head_a, t_list **head_b, char rotate_type)
{
	rotate(head_a, rotate_type);
	rotate(head_b, rotate_type);
	ft_printf("rr\n");
}

void	reverse_rotate(t_list **head, char rr_type)
{
	t_list	*last;
	t_list	*curr;

	if (!head || !*head || !(*head)->next)
		return ;
	curr = *head;
	while (curr->next)
	{
		if (!curr->next->next)
			break ;
		curr = curr->next;
	}
	last = curr->next;
	curr->next = NULL;
	last->next = *head;
	*head = last;
	if (rr_type == 'a')
		ft_printf("rra\n");
	else if (rr_type == 'b')
		ft_printf("rrb\n");
}

void	rrr(t_list **head_a, t_list **head_b, char rr_type)
{
	reverse_rotate(head_a, rr_type);
	reverse_rotate(head_b, rr_type);
	ft_printf("rrr\n");
}
