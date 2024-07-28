/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:06:23 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/01/21 12:06:25 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "LIBFT/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_stack
{
	int					value;
	int					index;
	int					small_sort_index;
	int					position;
	int					target_position;
	int					cost_a;
	int					cost_b;
	struct s_stack		*next;
}	t_stack;

// ** main.c ** //
void	ft_error(void);
int		check_if_sorted(t_stack *stack);
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);
int		main(int argc, char **argv);

// ** ft_printf_checks ** //
void	print_stack_value(t_stack *stack);
void	print_stack_index(t_stack *stack);
void	print_stack_small_index(t_stack *stack);
void	print_stack_position(t_stack *stack);
void	print_stack_cost(t_stack *stack);
void	print_stack_tarpos(t_stack *stack);

// ** process_args.c ** //
char	**two_args(char **argv);
int		count_args(char **argv);
void	process_args(int argc, char **argv, int *use_argc, char ***use_argv);

// ** is_correct_input.c ** //
int		has_duplicates(char **argv);
int		is_number(char *argv);
int		is_zero(char *argv);
int		is_correct_input(char **argv);

// ** assist_correct_input.c ** //
int		is_digit(char c);
int		is_sign(char c);
int		nb_str_cmp(const char *s1, const char *s2);
int		has_greater_than_max_int(char *argv);

// ** initstack.c ** //
t_stack	*fill_stack(int argc, char **argv);
t_stack	*find_highest_unassigned(t_stack **stack_a, int value);
void	assign_index(t_stack *stack_a, int stack_size);

// ** sort_small.c ** //
void	initialise_small_sort_index(t_stack **stack_a);
t_stack	*find_highest_unassigned_sml(t_stack **stack_a, int value);
void	assign_small_sort_index(t_stack **stack_a);
void	sort_small_index(t_stack **stack_a);
void	sort_small(t_stack **stack_a);

// ** sort_big.c ** //
int		get_smallest_index_position(t_stack **stack);
void	sort_big(t_stack **stack_a, t_stack **stack_b);
void	push_save_3(t_stack **stack_a, t_stack **stack_b);
void	ascending_order(t_stack **stack);

// ** target_position.c ** //
int		find_target_position(t_stack **stack_a, int b_index,
			int target_index, int target_position);
void	assign_target_position(t_stack **stack_a, t_stack **stack_b);

// ** cost_analysis.c ** //
void	assign_cost(t_stack **stack_a, t_stack **stack_b);
void	execute_cheap_seq(t_stack **stack_a, t_stack **stack_b);

// ** move_seq.c ** //
void	seq_rot_ab(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	seq_rev_rot_ab(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	seq_a_stack(t_stack **stack, int cost);
void	seq_b_stack(t_stack **stack, int cost);
void	execute_sequence(t_stack **stack_a, t_stack **stack_b,
			int cost_a, int cost_b);

// ** stack.c ** //
t_stack	*get_tail(t_stack *stack);
t_stack	*get_penultimate(t_stack *stack);
t_stack	*create_node(int value);
void	add_tail(t_stack **stack, t_stack *node);
int		find_stack_size(t_stack *stack);

// ** rotate.c ** //
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

// ** rev_rotate.c ** //
void	rev_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// ** swap.c ** //
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// ** push.c ** //
void	push(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

// ** utils.c ** //
void	free_stack(t_stack **stack);
void	assign_position(t_stack *stack);
int		calc_absolute(int a);

#endif