/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:17:19 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/06/05 11:17:20 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_save_3(t_stack **stack_a, t_stack **stack_b)
{
	int		stack_a_size;

	stack_a_size = find_stack_size(*stack_a);
	while (stack_a_size > 3)
	{
		pb(stack_a, stack_b);
		stack_a_size--;
	}
}

int	get_smallest_index_position(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	if (!current)
		return (0);
	assign_position(*stack);
	while (current)
	{
		if (current->index == 1)
			return (current->position);
		else
			current = current->next;
	}
	return (0);
}

void	ascending_order(t_stack **stack)
{
	int		smallest_index_position;

	smallest_index_position = get_smallest_index_position(stack);
	while ((*stack)->index != 1)
	{
		if (smallest_index_position <= find_stack_size(*stack) / 2)
			ra(stack);
		else
			rra(stack);
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	push_save_3(stack_a, stack_b);
	sort_small_index(stack_a);
	while (*stack_b)
	{
		assign_target_position(stack_a, stack_b);
		assign_cost(stack_a, stack_b);
		execute_cheap_seq(stack_a, stack_b);
	}
	if (!(check_if_sorted(*stack_a)))
		ascending_order(stack_a);
}
