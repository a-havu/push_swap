/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:04:39 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/24 10:35:52 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	get_push_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

static void	set_targets_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target_node;
	t_stack	*temp_b;
	long	closest_smaller;

	while(stack_a)
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
}

void	check_min_on_top(t_stack **stack_a)
{
	t_stack	*min_node;
	
	min_node = smallest_value(*stack_a);
	while (*stack_a != min_node)
	{
		if (min_node->above_median)
			ra(stack_a);
		else if (!(min_node->above_median))
			rra(stack_a);
	}
}
	