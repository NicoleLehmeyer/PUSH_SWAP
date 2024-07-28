/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:57:26 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/05/28 08:57:27 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit (1);
}

int	check_if_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !(check_if_sorted(*stack_a)))
		sa(stack_a);
	else if (stack_size == 3 && !(check_if_sorted(*stack_a)))
		sort_small(stack_a);
	else if (stack_size > 3 && !(check_if_sorted(*stack_a)))
		sort_big(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**use_argv;
	int		use_argc;

	if (argc == 1)
		return (0);
	process_args(argc, argv, &use_argc, &use_argv);
	if (!is_correct_input(use_argv))
		ft_error();
	stack_b = NULL;
	stack_a = fill_stack(use_argc, use_argv);
	stack_size = find_stack_size(stack_a);
	assign_index(stack_a, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
