/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:43:35 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/17 12:44:05 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	handle_up_to_3(t_list **head)
{
	while (!is_ordered(*head, &is_ascending))
	{
		if (!is_ascending(*(int *)(*head)->content,
			*(int *)ft_lstlast(*head)->content))
		{
			if ((*head)->next->next
				&& !is_ascending(*(int *)(*head)->content,
				*(int *)(*head)->next->content))
				swap(head, 'a');
			reverse_rotate(head, 'a');
		}
		else
		{
			if (is_ascending(*(int *)(*head)->content,
				*(int *)(*head)->next->content)
				&& !is_ascending(*(int *)(*head)->next->content,
				*(int *)ft_lstlast(*head)->content))
				reverse_rotate(head, 'a');
			swap(head, 'a');
		}
	}
}

void	sort_bigger_stack(t_list **head_a, t_list **head_b)
{
	t_list	*cheapest;
	t_list	*max;
	int		origin_rotations;
	int		dest_rotations;

	push(head_b, head_a, 'b');
	push(head_b, head_a, 'b');
	while (ft_lstsize(*head_a) > 3)
	{
		cheapest = find_cheapest(*head_b, *head_a, 'd');
		origin_rotations = rotations_to_top(*head_a, cheapest);
		dest_rotations = right_position_at_dest(cheapest, *head_b, 'd');
		if (origin_rotations > 0 && dest_rotations > 0)
			handle_rotation_a(head_a, head_b, 'd');
		else if (origin_rotations < 0 && dest_rotations < 0)
			handle_reverse_rotation_a(head_a, head_b, 'd');
		else
			handle_exotic_rotation_a(head_a, head_b, 'd');
		push(head_b, head_a, 'b');
	}
	handle_up_to_3(head_a);
	max = ft_lst_find_max(*head_b);
	while (*head_b != max)
		rotate(head_b, 'b');
}
