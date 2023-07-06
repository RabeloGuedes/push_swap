/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:32:58 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/06 20:32:51 by arabelo-         ###   ########.fr       */
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

t_list	*create_node(int data);
t_list	*create_nodes(char **args);

// nodes

// movements

void	swap(t_list **stack, char swap_type);
void	ss(t_list *stack_a, t_list *stack_b, char swap_type);
void	push(t_list *dest_top, t_list *origin_top);
void	pa(t_list *head_a, t_list *head_b);

// movements

#endif