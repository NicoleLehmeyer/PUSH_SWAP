/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correct_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:56:23 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/05/28 08:56:25 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && (argv[i + 1]) != '\0')
		i++;
	while (is_digit(argv[i]) && argv[i])
		i++;
	if (!is_digit(argv[i]) && argv[i] != '\0')
		return (0);
	return (1);
}

int	is_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] != '\0' && argv[i] == '0')
		i++;
	if (argv[i] == '\0')
		return (1);
	return (0);
}

int	has_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (nb_str_cmp(argv[i], argv[j]) == 0 && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_correct_input(char **argv)
{
	int	i;
	int	nb_zero_args;

	nb_zero_args = 0;
	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
		nb_zero_args += is_zero(argv[i]);
		i++;
	}
	if (nb_zero_args > 1)
		return (0);
	if (has_duplicates(argv) || has_greater_than_int_max(argv))
		return (0);
	return (1);
}
