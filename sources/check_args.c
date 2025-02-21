/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:00:27 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/31 13:11:44 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	int_ok(char *arg)
{
	long long	num;

	num = ft_atoi_longlong(arg);
	if (num > INT_MAX || num < INT_MIN || ft_strlen(arg) > 11)
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
	int		i;

	i = 0;
	if (!ft_isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+')
		return (0);
	else if (arg[i] == '-')
		i++;
	else if (arg[i] == '+')
		i++;
	if (!ft_isdigit(arg[i]))
		return (0);
	while (arg[i] >= '0' && arg[i] <= '9')
		i++;
	if (arg[i] && !ft_isdigit(arg[i]))
		return (0);
	return (1);
}

char	**check_args(char **argv)
{
	int	i;

	i = 1;
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
