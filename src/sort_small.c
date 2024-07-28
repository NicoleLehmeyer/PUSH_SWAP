/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:03:25 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/06/05 13:03:27 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	initialise_small_sort_index(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	while (current)
	{
		current->small_sort_index = 0;
		current = current->next;
	}
}

t_stack	*find_highest_unassigned_sml(t_stack **stack_a, int value)
{
	t_stack	*current;
	t_stack	*highest;

	current = *stack_a;
	highest = NULL;
	value = INT_MIN;
	while (current)
	{
		if (current->small_sort_index == 0 && current->value == INT_MIN)
			current->small_sort_index = 1;
		if (current->small_sort_index == 0 && current->value > value)
		{
			highest = current;
			value = current->value;
			current = *stack_a;
		}
		else
			current = current->next;
	}
	return (highest);
}

void	assign_small_sort_index(t_stack **stack_a)
{
	t_stack	*highest;
	int		stack_size;
	int		value;

	stack_size = find_stack_size(*stack_a);
	initialise_small_sort_index(stack_a);
	while (stack_size > 0)
	{
		value = INT_MIN;
		highest = find_highest_unassigned_sml(stack_a, value);
		if (highest)
			highest->small_sort_index = stack_size;
		stack_size--;
	}
}

void	sort_small_index(t_stack **stack_a)
{
	int	highest_index;

	if (check_if_sorted(*stack_a))
		return ;
	highest_index = 3;
	assign_small_sort_index(stack_a);
	if ((*stack_a)->small_sort_index == highest_index)
		ra(stack_a);
	else if ((*stack_a)->next->small_sort_index == highest_index)
		rra(stack_a);
	if ((*stack_a)->small_sort_index > (*stack_a)->next->small_sort_index)
		sa(stack_a);
}

void	sort_small(t_stack **stack_a)
{
	int	highest_index;

	if (check_if_sorted(*stack_a))
		return ;
	highest_index = 3;
	if ((*stack_a)->index == highest_index)
		ra(stack_a);
	else if ((*stack_a)->next->index == highest_index)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}
