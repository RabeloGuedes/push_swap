/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 08:21:25 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/10 18:52:09 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push(t_list **dest_top, t_list **origin_top, char push_type)
{
	t_list	*second_origin;

	if (!origin_top || !*origin_top)
		return ;
	second_origin = (*origin_top)->next;
	(*origin_top)->next = *dest_top;
	*dest_top = *origin_top;
	*origin_top = second_origin;
	if (push_type == 'a')
		ft_printf("pa\n");
	else if (push_type == 'b')
		ft_printf("pb\n");
}
