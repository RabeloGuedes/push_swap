/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:58:07 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 08:18:44 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	display_nodes(int ac, char **av)
{
	Node	*head;
	Node	*curr;

	head = args_to_linked_list(av, ac);
	if (!head)
		return ;
	curr = head;
	ft_printf("[\n");
	while (!curr->is_last)
	{
		ft_printf("	{\n		data: %i,\n		is_first: %i,\n		is_last: %i,\n		next: %p,\n		prev: %p,\n		address: %p\n	},\n", curr->data, curr->is_first, curr->is_last, curr->next, curr->prev, curr);
		curr = curr->next;
		free(head);
		head = curr;
	}
	ft_printf("	{\n		data: %i,\n		is_first: %i,\n		is_last: %i,\n		next: %p,\n		prev: %p,\n		address: %p\n	}\n", curr->data, curr->is_first, curr->is_last, curr->next, curr->prev, curr);
	ft_printf("]\n");
	free(curr);
}

void	display_swap(int ac, char **av)
{
	Node	*head;
	Node	*save;
	Node	*curr;

	head = args_to_linked_list(av, ac);
	if (!head)
		return ;
	curr = head;
	save = head;
	ft_printf("Before Swap A:\n");
	ft_printf("[\n");
	while (!curr->is_last)
	{
		ft_printf("	{\n		data: %i,\n		is_first: %i,\n		is_last: %i,\n		next: %p,\n		prev: %p,\n		address: %p\n	},\n", curr->data, curr->is_first, curr->is_last, curr->next, curr->prev, curr);
		curr = curr->next;
		head = curr;
	}
	ft_printf("	{\n		data: %i,\n		is_first: %i,\n		is_last: %i,\n		next: %p,\n		prev: %p,\n		address: %p\n	}\n", curr->data, curr->is_first, curr->is_last, curr->next, curr->prev, curr);
	ft_printf("]\n");
	curr = save;
	sa(save);
	ft_printf("After Swap A:\n");
	while (!curr->is_last)
	{
		ft_printf("	{\n		data: %i,\n		is_first: %i,\n		is_last: %i,\n		next: %p,\n		prev: %p,\n		address: %p\n	},\n", curr->data, curr->is_first, curr->is_last, curr->next, curr->prev, curr);
		curr = curr->next;
		free(save);
		save = curr;
	}
	ft_printf("	{\n		data: %i,\n		is_first: %i,\n		is_last: %i,\n		next: %p,\n		prev: %p,\n		address: %p\n	}\n", curr->data, curr->is_first, curr->is_last, curr->next, curr->prev, curr);
	ft_printf("]\n");
	free(curr);
}

int	main(int ac, char **av)
{

	if (ac > 1)
	{
		if (!args_checker(++av))
			return (0);
		display_nodes(ac - 1, av);
		display_swap(ac - 1, av);
	}
	return (0);
}
