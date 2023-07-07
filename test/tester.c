/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:58:07 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/07 11:29:17 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	test_push(char **args)
{
	t_list	**head_a;
	t_list	**head_b;
	char	**args_b;

	head_a = (t_list **)malloc(sizeof(t_list *));
	head_b = (t_list **)malloc(sizeof(t_list *));
	args_b = (char **)malloc(sizeof(char *));
	*args_b = (char *)malloc(sizeof(char) + 1);
	args_b[0][0] = '6';
	args_b[0][1] = '\0';
	*head_a = create_nodes(args);
	*head_b = create_nodes(args_b);
	if (!*head_a || !*head_b)
		return ;
	display_push(head_a, head_b);
	free_nodes(*head_a);
	free_nodes(*head_b);
	free(head_a);
	free(head_b);
	free(*args_b);
	free(args_b);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!args_checker(++av))
			return (0);
		test_push(av);
	}
	return (0);
}
