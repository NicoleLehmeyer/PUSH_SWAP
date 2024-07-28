/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:19:52 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/05/30 15:19:53 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	**two_args(char **argv)
{
	char	**new_argv;
	char	*all_args;
	char	*temp;

	temp = ft_strdup(argv[1]);
	temp = ft_strjoin(ft_strjoin(argv[0], " "), temp);
	all_args = ft_strjoin(argv[0], temp);
	free(temp);
	new_argv = ft_split(all_args, ' ');
	free(all_args);
	return (new_argv);
}

int	count_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	process_args(int argc, char **argv, int *use_argc, char ***use_argv)
{
	if (argc == 2)
	{
		*use_argv = two_args(argv);
		*use_argc = count_args(*use_argv);
	}
	else
	{
		*use_argv = argv;
		*use_argc = argc;
	}
}
