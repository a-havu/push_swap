/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:00:07 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/24 10:38:12 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}