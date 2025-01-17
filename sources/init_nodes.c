/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:04:39 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/16 16:20:43 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	get_push_cost(t_stack *finder, t_stack *target)
{
	int	len_finder;
	int	len_target;

	len_finder = stack_size(finder);
	len_finder = stack_size(target);
	while (finder)
	{
		finder->push_cost = finder->index;
		if (!(finder->above_median))
			finder->push_cost = len_finder - (finder->index);
		if (finder->target_node->above_median)
			finder->push_cost += finder->target_node->index;
	}
}

static void	set_target_nodes(t_stack *finder, t_stack *target_stack)
{
	t_stack	*target_node;
	t_stack	*subject;
	long	closest_smaller;

	while(finder)
	{
		subject = target_stack;
		closest_smaller = LONG_MIN;
		while (subject)
		{
			if (subject->value < finder->value
			&& subject->value > closest_smaller)
			{
				closest_smaller = subject->value;
				target_node = subject;
			}
			subject = subject->next;
		}
		if (closest_smaller == LONG_MIN)
			finder->target_node = biggest_value(target_stack);
		else
			finder->target_node = target_node;
		finder = finder->next;
	}
}

static void	set_index(t_stack *stack)
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
		if (i > median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	init_nodes_in_a(t_stack **stack_a, t_stack **stack_b)
{
	set_index(*stack_a);
	set_index(*stack_b);
	set_target_nodes(stack_a, stack_b);
	get_push_cost(stack_a, stack_b);
}