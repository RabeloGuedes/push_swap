/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:17:56 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/17 13:43:59 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	handle_rotation_b(t_list **head_origin,
	t_list **head_dest, char position_type)
{
	int		origin_rotations;
	int		dest_rotations;
	t_list	*cheapest;

	cheapest = find_cheapest(*head_origin, *head_dest, position_type);
	origin_rotations = rotations_to_top(*head_origin, cheapest);
	dest_rotations = right_position_at_dest(cheapest, *head_dest,
			position_type);
	while (origin_rotations && dest_rotations)
	{
		rr(head_origin, head_dest, '2');
		origin_rotations--;
		dest_rotations--;
	}
	while (origin_rotations)
	{
		rotate(head_origin, 'b');
		origin_rotations--;
	}
	while (dest_rotations)
	{
		rotate(head_dest, 'a');
		dest_rotations--;
	}
}

void	handle_reverse_rotation_b(t_list **head_origin,
	t_list **head_dest, char position_type)
{
	int		origin_rotations;
	int		dest_rotations;
	t_list	*cheapest;

	cheapest = find_cheapest(*head_origin, *head_dest, position_type);
	origin_rotations = rotations_to_top(*head_origin, cheapest);
	dest_rotations = right_position_at_dest(cheapest, *head_dest,
			position_type);
	while (origin_rotations && dest_rotations)
	{
		rrr(head_origin, head_dest, '2');
		origin_rotations++;
		dest_rotations++;
	}
	while (origin_rotations)
	{
		reverse_rotate(head_origin, 'b');
		origin_rotations++;
	}
	while (dest_rotations)
	{
		reverse_rotate(head_dest, 'a');
		dest_rotations++;
	}
}

void	exotic_rotation_b_1(t_list **head_origin, t_list **head_dest,
	int	*origin_rotations, int *dest_rotations)
{
	while (*origin_rotations < 0)
	{
		reverse_rotate(head_origin, 'b');
		*origin_rotations = *origin_rotations + 1;
	}
	while (*dest_rotations > 0)
	{
		rotate(head_dest, 'a');
		*dest_rotations = *dest_rotations - 1;
	}
}

void	exotic_rotation_b_2(t_list **head_origin, t_list **head_dest,
	int	*origin_rotations, int *dest_rotations)
{
	while (*origin_rotations > 0)
	{
		rotate(head_origin, 'b');
		*origin_rotations = *origin_rotations - 1;
	}
	while (*dest_rotations < 0)
	{
		reverse_rotate(head_dest, 'a');
		*dest_rotations = *dest_rotations + 1;
	}
}

void	handle_exotic_rotation_b(t_list **head_origin,
	t_list **head_dest, char position_type)
{
	int		origin_rotations;
	int		dest_rotations;
	t_list	*cheapest;

	cheapest = find_cheapest(*head_dest, *head_origin, position_type);
	origin_rotations = rotations_to_top(*head_origin, cheapest);
	dest_rotations = right_position_at_dest(cheapest, *head_dest,
			position_type);
	exotic_rotation_b_1(head_origin, head_dest,
		&origin_rotations, &dest_rotations);
	exotic_rotation_b_2(head_origin, head_dest,
		&origin_rotations, &dest_rotations);
}
