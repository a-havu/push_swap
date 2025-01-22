/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:00:07 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/21 12:10:38 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*smallest_value(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*biggest_value(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while(stack)
	{
		tmp = stack;
		stack = stack->next;
		tmp->prev = NULL;
		free(tmp);
	}
}

t_stack	*find_cheapest_node(t_stack *stack)
{
	long	cheapest_push_cost;
	t_stack	*cheapest_node;

	cheapest_push_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_push_cost)
		{
			cheapest_push_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

int	is_stack_sorted(t_stack *stack)
{
	int	i;
	i = stack->value;

	while(stack)
	{
		if (i > stack->value)
			return (0);
		i = stack->value;
		stack = stack->next;
	}
	return (1);
}

void print_list(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("index: %d value: %d\n", tmp->index, tmp->value);
		tmp = tmp->next;
	}
}