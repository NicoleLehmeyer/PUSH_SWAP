/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:49:24 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/06/08 19:49:25 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_stack_value(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}

void	print_stack_index(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		ft_printf("%d\n", current->index);
		current = current->next;
	}
}

void	print_stack_small_index(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		ft_printf("%d\n", current->small_sort_index);
		current = current->next;
	}
}

void	print_stack_cost(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		ft_printf("Cost_a: %d\nCost_b: %d\n", current->cost_a, current->cost_b);
		current = current->next;
	}
}

void	print_stack_tarpos(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		ft_printf("VALUE:%d\n	Position:%d\n	Target position:%d\n",
			current->index, current->position, current->target_position);
		current = current->next;
	}
}
