/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 08:21:25 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 20:36:09 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// void	push(t_list *dest_top, t_list *origin_top)
// {
// 	if (!origin_top)
// 		return ;
// 	if (!dest_top)
// 	{
// 		dest_top = origin_top;
// 		origin_top->next->prev = NULL;
// 	}
// 	else if (!origin_top->next && !origin_top->prev)
// 	{
// 		origin_top->next = dest_top;
// 		dest_top->prev = origin_top;
// 	}
// 	else
// 	{
// 		origin_top->next->prev = NULL;
// 		dest_top->prev = origin_top;
// 		origin_top->next = dest_top;
// 	}
// }

// void	pa(t_list *head_a, t_list *head_b)
// {
// 	push(head_a, head_b);
// }

// void	pb(t_list *head_b, t_list *head_a)
// {
// 	push(head_b, head_a);
// }
