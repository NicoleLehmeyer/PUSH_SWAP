/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:27:02 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/01/21 13:27:04 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack && !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	assign_position(t_stack *stack)
{
	t_stack	*current;
	int		position;

	current = stack;
	position = 0;
	while (current)
	{
		current->position = position;
		position++;
		current = current->next;
	}
}

int	calc_absolute(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
