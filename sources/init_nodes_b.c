/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:51:51 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/28 10:46:01 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest_in_stack)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	set_targets_b(t_stack *stack_b, t_stack *stack_a)
{
	t_stack	*target_node;
	t_stack	*subject;
	long	closest_bigger;

	while (stack_b)
	{
		subject = stack_a;
		closest_bigger = LONG_MAX;
		while (subject)
		{
			if (subject->value > stack_b->value \
			&& subject->value < closest_bigger)
			{
				closest_bigger = subject->value;
				target_node = subject;
			}
			subject = subject->next;
		}
		if (closest_bigger == LONG_MAX)
			stack_b->target_node = smallest_value(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_nodes_in_b(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_targets_b(stack_b, stack_a);
}
