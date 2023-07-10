/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:11:35 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/10 14:10:33 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(char **av)
{
	t_list	**head_a;
	t_list	**head_b;

	head_a = (t_list **)malloc(sizeof(t_list *));
	head_b = (t_list **)malloc(sizeof(t_list *));
	if (!head_a || !head_b)
		return ;
	*head_a = create_nodes(av);
	ft_printf("Is ordered: %i\n", is_ordered(head_a, is_ascending));
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
