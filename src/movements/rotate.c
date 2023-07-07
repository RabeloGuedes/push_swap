/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:14:06 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/07 17:51:02 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate(t_list **head, char rotate_type)
{
	t_list	*temp;

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

}