/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:00:07 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/30 16:41:54 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*smallest_value(t_stack *stack)
{
	long	min;
	t_stack	*min_node;
	t_stack	*tmp;

	min = LONG_MAX;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

t_stack	*biggest_value(t_stack *stack)
{
	long	max;
	t_stack	*max_node;
	t_stack	*tmp;

	max = LONG_MIN;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		tmp->prev = NULL;
		free(tmp);
	}
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
