/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:37:43 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/05/29 12:37:46 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*get_tail(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_penultimate(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
		ft_printf("Malloc unsuccessful");
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	add_tail(t_stack **stack, t_stack *node)
{
	t_stack	*tail;

	if (!node)
		ft_printf("Node is NULL");
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tail = get_tail(*stack);
	tail->next = node;
}

int	find_stack_size(t_stack *stack)
{
	int		size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
