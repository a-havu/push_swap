/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:00:27 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/28 15:18:42 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	int_ok(char *arg)
{
	long long int	num;

	num = ft_atoi_longlong(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	else
		return (1);
}

int	find_duplicate(char **argv, int i)
{
	int	k;

	while (argv[i])
	{
		k = i + 1;
		while (argv[k])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[k]))
				return (1);
			else
				k++;
		}
		i++;
	}
	return (0);
}

int	arg_is_number(char *arg)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(arg))
	{
		if (ft_isdigit(arg[i]) || (arg[i] == '-' && ft_isdigit(arg[i + 1])) \
		|| (arg[i] == '+' && ft_isdigit(arg[i + 1])))
			i++;
		else
			return (0);
	}
	return (1);
}

char	**check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		argv = split_args(argv[1]);
		if (!argv)
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
	}
	if (find_duplicate(argv, i))
		return (NULL);
	while (argv[i])
	{
		if (!arg_is_number(argv[i]) || !int_ok(argv[i]))
			return (NULL);
		else
			i++;
	}
	return (argv);
}
