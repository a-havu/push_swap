/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:24:18 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/31 12:57:49 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_everything(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		arg[i] = NULL;
		i++;
	}
	free(arg);
}

static int	check_split_arg(char **split_arg)
{
	int	i;

	i = 0;
	if (find_duplicate(split_arg, i))
		return (0);
	while (split_arg[i])
	{
		if (!arg_is_number(split_arg[i]) || !int_ok(split_arg[i]))
			return (0);
		else
			i++;
	}
	return (1);
}

char	**split_args(char *arg)
{
	char	**split_arg;
	int		i;

	i = 0;
	split_arg = ft_split(arg, ' ');
	if (!split_arg || !split_arg[0])
	{
		free(split_arg);
		return (NULL);
	}
	if (!check_split_arg(split_arg))
	{
		free_everything(split_arg);
		return (NULL);
	}
	return (split_arg);
}
