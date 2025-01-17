/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:00:07 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/16 11:30:15 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	smallest_value(t_stack *stack)
{
	int		res;
	t_stack	*tmp;

	tmp = stack;
	res = stack->value;
	while (tmp)
	{
		if (res > tmp->value)
			res = tmp->value;
		tmp = tmp->next;
	}
	return (res);
}

int	biggest_value(t_stack *stack)
{
	int		res;
	t_stack	*tmp;

	tmp = stack;
	res = stack->value;
	while (tmp)
	{
		if (res < tmp->value)
			res = tmp->value;
		tmp = tmp->next;
	}
	return (res);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while(stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}