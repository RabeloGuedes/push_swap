/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:32:58 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/19 15:07:11 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/ft_printf.h"

typedef struct s_node_infos
{
	t_list	*address;
	char	rotate_mode;
	int		qtd_movements;
}				t_node_info;

// helpers

int			are_arg_num(const char *str);
int			a_is_int_range(const char *str);
int			duplicates_checker(char **args);
int			args_checker(char **args);
int			is_ascending(int a, int b);
int			is_descending(int a, int b);
int			is_ordered(t_list *head, int (*cmp)(int, int));
int			size_checker(t_list **head);
t_list		*ft_lst_find_max(t_list *head);
t_list		*ft_lst_find_min(t_list *head);
int			rotations_to_top(t_list *head, t_list *searched_node);
int			rotations_to_bottom(t_list *head, t_list *searched_node);
int			right_position_at_dest(t_list *new_node,
				t_list *head, char position_type);
t_list		*find_the_right_position_a(t_list *new_node, t_list *head);
t_list		*find_the_right_position_b(t_list *new_node, t_list *head);
t_list		*find_cheapest(t_list *head_dest,
				t_list *head_origin, char position_type);
void		handle_rotation_a(t_list **head_origin,
				t_list **head_dest, char position_type);
void		handle_reverse_rotation_a(t_list **head_origin,
				t_list **head_dest, char position_type);
void		exotic_rotation_a_1(t_list **head_origin, t_list **head_dest,
				int	*origin_rotations, int *dest_rotations);
void		exotic_rotation_a_2(t_list **head_origin, t_list **head_dest,
				int	*origin_rotations, int *dest_rotations);
void		handle_exotic_rotation_a(t_list **head_origin,
				t_list **head_dest, char position_type);
void		handle_rotation_b(t_list **head_origin,
				t_list **head_dest, char position_type);
void		handle_reverse_rotation_b(t_list **head_origin,
				t_list **head_dest, char position_type);
void		exotic_rotation_b_2(t_list **head_origin, t_list **head_dest,
				int	*origin_rotations, int *dest_rotations);
void		exotic_rotation_b_1(t_list **head_origin, t_list **head_dest,
				int	*origin_rotations, int *dest_rotations);
void		handle_exotic_rotation_b(t_list **head_origin,
				t_list **head_dest, char position_type);
void		handle_up_to_3(t_list **head);
void		sort_bigger_stack(t_list **head_a, t_list **head_b);
int			rotations_cost(t_list *searched_node, t_list *head_origin,
				t_list *head_dest, char order_type);

// helpers

// nodes

t_list		*create_node(int data);
t_list		*create_nodes(char **args);
void		free_nodes(t_list *head);

// nodes

// movements

void		swap(t_list **stack, char swap_type);
void		ss(t_list **stack_a, t_list **stack_b, char swap_type);
void		push(t_list **dest_top, t_list **origin_top, char push_type);
void		rotate(t_list **head, char rotate_type);
void		rr(t_list **head_a, t_list **head_b, char rotate_type);
void		reverse_rotate(t_list **head, char rr_type);
void		rrr(t_list **head_a, t_list **head_b, char rr_type);

// movements

void		push_swap(char **av);
void		handle_up_to_3(t_list **head);
void		handle_movement(t_list **head_a, t_list **head_b);

// tests

void		display_node_infos(t_list *node);
void		display_nodes(t_list *stack);
void		display_nodes_simple(t_list *stack);

// tests

#endif