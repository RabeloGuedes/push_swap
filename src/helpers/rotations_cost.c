/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:16:45 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/17 13:16:56 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	rotations_cost(t_list *searched_node, t_list *head_origin,
	t_list *head_dest, char order_type)
{
	return (ft_abs_value(rotations_to_top(head_origin, searched_node))
		+ ft_abs_value(right_position_at_dest(searched_node, head_dest,
				order_type)));
}
