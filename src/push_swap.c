/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:11:35 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/17 12:44:01 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	handle_movement(t_list **head_a, t_list **head_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*head_a);
	if (stack_size <= 3)
		handle_up_to_3(head_a);
	else
		sort_bigger_stack(head_a, head_b);
}

void	push_swap(char **av)
{
	t_list	**head_a;
	t_list	**head_b;

	head_a = (t_list **)malloc(sizeof(t_list *));
	head_b = (t_list **)malloc(sizeof(t_list *));
	if (!head_a || !head_b)
		return ;
	*head_a = create_nodes(av);
	*head_b = NULL;
	ft_printf("Stack A Before: \n");
	display_nodes_simple(*head_a);
	ft_printf("Stack b Before: \n");
	display_nodes_simple(*head_b);
	if (size_checker(head_a) && !is_ordered(*head_a, &is_ascending))
		handle_movement(head_a, head_b);
	ft_printf("Stack A After: \n");
	display_nodes_simple(*head_a);
	ft_printf("Stack B After: \n");
	display_nodes_simple(*head_b);
	free_nodes(*head_a);
	free_nodes(*head_b);
	free(head_a);
	free(head_b);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!args_checker(++av))
			return (0);
		push_swap(av);
	}
	return (0);
}
