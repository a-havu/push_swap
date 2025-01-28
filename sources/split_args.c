/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:24:18 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/28 15:13:17 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	**check_split_arg(char **split_arg)
{
	int	i;

	i = 0;
	if (find_duplicate(split_arg, i))
		return (NULL);
	while (split_arg[i])
	{
		if (!arg_is_number(split_arg[i]) || !int_ok(split_arg[i]))
			return (NULL);
		else
			i++;
	}
	return (split_arg);
}

char	**split_args(char *arg)
{
	char	**split_arg;

	split_arg = ft_split(arg, ' ');
	if (!split_arg)
		return (NULL);
	split_arg = check_split_arg(split_arg);
	return (split_arg);
}
