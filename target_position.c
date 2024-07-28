/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:04:27 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/06/05 19:04:29 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// First while loop checks for an index > b_index and < target_index
// If an element in stack_a fulfils these conditions,
// 		the target index will have changed
//		from its previously assigned value of INT_MAX
// If target_index is not INT_MAX, the target position is returned
// Otherwise, this means there are no indexes higher than b_index in stack_a
// In this case, the target will be the smallest index in stack_a
// We reset our current_a pointer to the beginning of stack_a
// And look for that in the second while loop, reassigning target index
//		each time we find an a_stack index less than the current target index,
//		until we have the smallest value, then we return its target position

int	find_target_position(t_stack **stack_a, int b_index,
	int target_index, int target_position)
{
	t_stack	*current_a;

	current_a = *stack_a;
	while (current_a)
	{
		if (current_a->index > b_index && current_a->index < target_index)
		{
			target_index = current_a->index;
			target_position = current_a->position;
		}
		current_a = current_a->next;
	}
	if (target_index != INT_MAX)
		return (target_position);
	current_a = *stack_a;
	while (current_a)
	{
		if (current_a->index < target_index)
		{
			target_index = current_a->index;
			target_position = current_a->position;
		}
		current_a = current_a->next;
	}
	return (target_position);
}

void	assign_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_b;

	current_b = *stack_b;
	assign_position(*stack_a);
	assign_position(*stack_b);
	while (current_b)
	{
		current_b->target_position = find_target_position(stack_a,
				current_b->index, INT_MAX, current_b->target_position);
		current_b = current_b->next;
	}
}
