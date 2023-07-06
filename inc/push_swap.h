/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:32:58 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 13:05:20 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/ft_printf.h"

// structs

typedef struct s_point
{
	int				data;
	struct s_point	*next;
	struct s_point	*prev;
}				t_node;

typedef struct s_stack
{
	t_node	**head;
	t_node	**tail;
}				t_stack;

// structs

// helpers

int		are_arg_num(const char *str);
int		a_is_int_range(const char *str);
int		duplicates_checker(char **args);
int		args_checker(char **args);

// helpers

// nodes

int		bind_nodes(t_node *prev_node, t_node *new_node);
t_node	*create_node(void);
t_node	*create_nodes(size_t nodes_amount, t_stack *stack);
void	fill_nodes(t_node *head, char **args);
void	args_to_linked_list(char **args, size_t nodes_amount, t_stack *stack);

// nodes

// movements

void	swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_a);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	push(t_node *dest_top, t_node *origin_top);
void	pa(t_node *head_a, t_node *head_b);

// movements

#endif