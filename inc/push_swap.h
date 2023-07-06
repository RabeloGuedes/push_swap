/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:32:58 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 08:04:29 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/ft_printf.h"

// helpers

int	are_arg_num(const char *str);
int a_is_int_range(const char *str);
int	duplicates_checker(char **args);
int	args_checker(char **args);

// helpers

// nodes

typedef struct	t_point
{
	int				data;
	struct t_point *next;
	struct t_point *prev;
	int				is_first;
	int				is_last;
}				Node;

Node	*create_nodes(size_t nodes_amount);
void	fill_nodes(Node *head, char **args);
Node	*args_to_linked_list(char **args, size_t nodes_amount);

// nodes

// movements

void	swap(Node *head);
void	sa(Node *head_a);
void	sb(Node *head_b);
void	ss(Node *head_a, Node *head_b);

// movements

#endif