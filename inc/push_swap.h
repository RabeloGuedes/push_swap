/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:32:58 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 10:01:25 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/ft_printf.h"

// helpers

int		are_arg_num(const char *str);
int		a_is_int_range(const char *str);
int		duplicates_checker(char **args);
int		args_checker(char **args);

// helpers

// nodes

typedef struct s_point
{
	int				data;
	struct s_point	*next;
	struct s_point	*prev;
}				t_node;

int		bind_nodes(t_node *prev_node, t_node *new_node);
t_node	*create_node(void);
t_node	*create_nodes(size_t nodes_amount);
void	fill_nodes(t_node *head, char **args);
t_node	*args_to_linked_list(char **args, size_t nodes_amount);

// nodes

// movements

void	swap(t_node *head);
void	sa(t_node *head_a);
void	sb(t_node *head_b);
void	ss(t_node *head_a, t_node *head_b);

// movements

#endif