/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:33:08 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/10 14:35:31 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	size_checker(t_list **head)
{
	int	size;

	if (!head || !*head)
		return (0);
	size = ft_lstsize(*head);
	if (size > 1)
		return (1);
	return (0);
}
