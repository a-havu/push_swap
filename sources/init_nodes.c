/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:04:39 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/28 14:17:42 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_cheapest_node(t_stack *stack)
{
	long	cheapest_cost;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_cost)
		{
			cheapest_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest_in_stack = true;
}

static void	get_push_cost(t_stack *finder, t_stack *target)
{
	int	len_finder;
	int	len_target;

	len_finder = stack_size(finder);
	len_target = stack_size(target);
	while (finder)
	{
		finder->push_cost = finder->index;
		if (!(finder->above_median))
			finder->push_cost = len_finder - (finder->index);
		if (finder->target_node->above_median)
			finder->push_cost += finder->target_node->index;
		else
			finder->push_cost += len_target - (finder->target_node->index);
		finder = finder->next;
	}
}

static void	set_targets_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target_node;
	t_stack	*temp_b;
	long	closest_smaller;

	while (stack_a)
	{
		closest_smaller = LONG_MIN;
		temp_b = stack_b;
		while (temp_b)
		{
			if ((temp_b)->value < (stack_a)->value
				&& (temp_b)->value > closest_smaller)
			{
				closest_smaller = (temp_b)->value;
				target_node = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (closest_smaller == LONG_MIN)
			stack_a->target_node = biggest_value(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

void	set_index(t_stack *stack)
{
	int	median;
	int	i;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	init_nodes_in_a(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_targets_a(stack_a, stack_b);
	get_push_cost(stack_a, stack_b);
	set_cheapest_node(stack_a);
}
