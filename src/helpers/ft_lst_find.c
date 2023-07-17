/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:52:49 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/17 13:16:35 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_list	*ft_lst_find_max(t_list *head)
{
	t_list	*max_node;

	if (!head)
		return (NULL);
	max_node = head;
	while (head)
	{
		if (*(int *)head->content > *(int *)max_node->content)
			max_node = head;
		head = head->next;
	}
	return (max_node);
}

t_list	*ft_lst_find_min(t_list *head)
{
	t_list	*min_node;

	if (!head)
		return (NULL);
	min_node = head;
	while (head)
	{
		if (*(int *)head->content < *(int *)min_node->content)
			min_node = head;
		head = head->next;
	}
	return (min_node);
}

t_list	*find_the_right_position_b(t_list *new_node, t_list *head_dest)
{
	int		new_node_content;
	int		head_dest_value;
	t_list	*save_head;

	if (!head_dest)
		return (NULL);
	new_node_content = *(int *)new_node->content;
	save_head = head_dest;
	while (head_dest)
	{
		head_dest_value = *(int *)head_dest->content;
		if (!head_dest->next && is_ascending(new_node_content, head_dest_value)
			&& is_descending(new_node_content, *(int *)save_head->content))
			return (head_dest);
		else if (head_dest->next
			&& is_ascending(new_node_content, head_dest_value)
			&& is_descending(new_node_content,
				*(int *)head_dest->next->content))
			return (head_dest);
		head_dest = head_dest->next;
	}
	return (NULL);
}

t_list	*find_the_right_position_a(t_list *new_node, t_list *head_dest)
{
	int		new_node_content;
	int		head_dest_value;
	t_list	*save_head;

	if (!head_dest)
		return (NULL);
	new_node_content = *(int *)new_node->content;
	save_head = head_dest;
	while (head_dest)
	{
		head_dest_value = *(int *)head_dest->content;
		if (!head_dest->next && is_descending(new_node_content, head_dest_value)
			&& is_ascending(new_node_content, *(int *)save_head->content))
			return (head_dest);
		else if (head_dest->next
			&& is_descending(new_node_content, head_dest_value)
			&& is_ascending(new_node_content,
				*(int *)head_dest->next->content))
			return (head_dest);
		head_dest = head_dest->next;
	}
	return (NULL);
}

t_list	*find_cheapest(t_list *head_dest, t_list *head_origin, char order_type)
{
	t_list	*cheapest;
	t_list	*save_origin_top;
	int		cheapest_rotations_origin;
	int		cheapest_rotations_dest;

	cheapest = head_origin;
	save_origin_top = head_origin;
	cheapest_rotations_origin = ft_abs_value(rotations_to_top(head_origin,
				head_origin));
	cheapest_rotations_dest = ft_abs_value(right_position_at_dest(head_origin,
				head_dest, order_type));
	head_origin = head_origin->next;
	while (head_origin)
	{
		if (cheapest_rotations_origin + cheapest_rotations_dest
			> rotations_cost(head_origin, save_origin_top,
				head_dest, order_type))
			cheapest = head_origin;
		head_origin = head_origin->next;
	}
	return (cheapest);
}
