/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:11:35 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/10 18:19:09 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	display_node_infos(t_list *node)
{
	ft_printf("	{\n		data: %i,\n", *(int *)(node->content));
	ft_printf("		next: %p,\n", node->next);
	ft_printf("		address: %p\n", node);
	ft_printf("	},\n");
}

void	display_nodes(t_list *stack)
{
	ft_printf("[\n");
	while (stack)
	{
		display_node_infos(stack);
		stack = stack->next;
	}
	ft_printf("]\n");
}

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

void	handle_movement(t_list **head_a, t_list **head_b)
{
	int	stack_size;

	(void)head_b;
	stack_size = ft_lstsize(*head_a);
	if (stack_size <= 3)
		handle_up_to_3(head_a);
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
	ft_printf("Before: \n");
	display_nodes(*head_a);
	if (size_checker(head_a))
		handle_movement(head_a, head_b);
	ft_printf("After: \n");
	display_nodes(*head_a);
	free_nodes(*head_a);
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
