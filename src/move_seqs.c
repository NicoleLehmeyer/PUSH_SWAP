/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_seqs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:10:36 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/06/05 19:10:38 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	seq_rot_ab(t_stack **stack_a,
	t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	seq_rev_rot_ab(t_stack **stack_a,
	t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	seq_a_stack(t_stack **stack, int cost)
{
	while (cost != 0)
	{
		if (cost > 0)
		{
			ra(stack);
			cost--;
		}
		else if (cost < 0)
		{
			rra(stack);
			cost++;
		}
	}
}

void	seq_b_stack(t_stack **stack, int cost)
{
	while (cost != 0)
	{
		if (cost > 0)
		{
			rb(stack);
			(cost)--;
		}
		else if (cost < 0)
		{
			rrb(stack);
			(cost)++;
		}
	}
}

void	execute_sequence(t_stack **stack_a,
	t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		seq_rot_ab(stack_a, stack_b, &cost_a, &cost_b);
	if (cost_a < 0 && cost_b < 0)
		seq_rev_rot_ab(stack_a, stack_b, &cost_a, &cost_b);
	seq_a_stack(stack_a, cost_a);
	seq_b_stack(stack_b, cost_b);
	pa(stack_a, stack_b);
}
