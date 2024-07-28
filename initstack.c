/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:19:04 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/01/21 12:19:06 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*fill_stack(int argc, char **argv)
{
	int			i;
	long int	nb;
	t_stack		*stack_a;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error();
		if (i == 1)
			stack_a = create_node(nb);
		else
		{
			add_tail(&stack_a, create_node(nb));
		}
		i++;
	}
	return (stack_a);
}

t_stack	*find_highest_unassigned(t_stack **stack_a, int value)
{
	t_stack	*current;
	t_stack	*highest;

	current = *stack_a;
	highest = NULL;
	value = INT_MIN;
	while (current)
	{
		if (current->index == 0 && current->value == INT_MIN)
			current->index = 1;
		if (current->index == 0 && current->value > value)
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

//ASSIGN_INDEX:
//Big while loop determines the next greatest index no to assign
//This begins at the stack size and decrements until 0
//The inner while loop searches through each node to find the
	//highest valued unassigned node. It is assigned 'highest'
//If the 'highest' pointer node is not NULL, its' value is assigned
	//the current stack size value
//Cont. as stack size decrements, assigning the next highest value
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*highest;
	int		value;

	while (stack_size > 0)
	{
		value = INT_MIN;
		highest = find_highest_unassigned(&stack_a, value);
		if (highest)
			highest->index = stack_size;
		stack_size--;
	}
}
