/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:00:27 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/31 12:46:08 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	int_ok(char *arg)
{
	long int	num;

	num = ft_atoi(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	else
		return (1);
}

static int	compare(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] - (unsigned char)s2[i] != 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static int	check_dup(int argc, char **argv)
{
    int	i;
    int	k;

    i = 1;
    k = 2;
    while (i < argc)
	{
		while (argv[k])
		{
			if (compare(argv[i], argv[k]))
				return (0);
			else
				k++;
		}
		i++;
	}
	return (1);
}

static int  input_nbrs(char *arg)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(arg))
	{
		if (ft_isdigit(arg[i]) || (arg[i] == '-' && ft_isdigit(arg[i + 1]))
		|| (arg[i] == '+' && ft_isdigit(arg[i + 1])))
			i++;
		else
			return (0);
    }
    return (1);
}

char     **check_args(int argc, char **argv)
{
    int     i;
    int     k;
    
    i = 1;
    k = 0;
    if (argc == 2)
	{
		argv = args_split(argv[i]);
		if (!argv)
			return (NULL);
	}
    while (argv[i])
    {
        if (!input_nbrs(argv[i]) || !check_dup(argc, argv) \
		|| !int_ok(argv[i]))
			return (NULL);
		else
			i++;
    }
    return (argv);
}
