/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_correct_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:01:14 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/05/28 09:01:27 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	nb_str_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int	has_greater_than_max_int(char *argv)
{
	int len;
	
	len = ft_strlen(argv);
	if (len >= 12)
		return (1);
	if (len == 11 && ft_strncmp((argv + 1), "2147483648", 10) > 0 && argv[0] == '-')
		return (1);
	if (len == 10 && ft_strncmp(argv, "2147483647", 10) > 0)
		return (1);
	else
		return (0);
}
