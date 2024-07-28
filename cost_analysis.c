/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:06:14 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/06/05 19:06:15 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	assign_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_b;
	int		stack_a_size;
	int		stack_b_size;

	current_b = *stack_b;
	stack_a_size = find_stack_size(*stack_a);
	stack_b_size = find_stack_size(*stack_b);
	while (current_b)
	{
		current_b->cost_b = current_b->position;
		if (current_b->position > (stack_b_size / 2))
			current_b->cost_b = -(stack_b_size - current_b->position);
		current_b->cost_a = current_b->target_position;
		if (current_b->target_position > (stack_a_size / 2))
			current_b->cost_a = -(stack_a_size - current_b->target_position);
		current_b = current_b->next;
	}
}

void	execute_cheap_seq(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_b;
	int		current_cost_a;
	int		current_cost_b;
	int		lowest_move_seq;

	current_b = *stack_b;
	lowest_move_seq = INT_MAX;
	while (current_b)
	{
		if (calc_absolute(current_b->cost_a)
			+ calc_absolute(current_b->cost_b) < lowest_move_seq)
		{
			lowest_move_seq = calc_absolute(current_b->cost_a)
				+ calc_absolute(current_b->cost_b);
			current_cost_a = current_b->cost_a;
			current_cost_b = current_b->cost_b;
		}
		current_b = current_b->next;
	}
	execute_sequence(stack_a, stack_b, current_cost_a, current_cost_b);
}
