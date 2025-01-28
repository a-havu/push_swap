/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:17:43 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/28 10:47:12 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_min_on_top(t_stack **stack_a)
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

static void	nodes_to_top(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	nodes_to_top(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest_node(*stack_a);
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while ((*stack_b) != cheapest->target_node && (*stack_a) != cheapest)
			rr(stack_a, stack_b);
		set_index(*stack_a);
		set_index(*stack_b);
	}
	else if (!(cheapest->above_median) \
			&& !(cheapest->target_node->above_median))
	{
		while ((*stack_b) != cheapest->target_node && (*stack_a) != cheapest)
			rrr(stack_a, stack_b);
		set_index(*stack_a);
		set_index(*stack_b);
	}
	nodes_to_top(stack_a, cheapest, 'a');
	nodes_to_top(stack_b, cheapest->target_node, 'b');
	pb(stack_a, stack_b);
}

void	sort_big(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		stack_len;

	stack_b = NULL;
	stack_len = stack_size(*stack_a);
	if (stack_len-- > 3 && !is_stack_sorted(*stack_a))
		pb(stack_a, &stack_b);
	if (stack_len-- > 3 && !is_stack_sorted(*stack_a))
		pb(stack_a, &stack_b);
	while (stack_len-- > 3 && !is_stack_sorted(*stack_a))
	{
		init_nodes_in_a(*stack_a, stack_b);
		move_a_to_b(stack_a, &stack_b);
	}
	sort_three(stack_a);
	while (stack_b)
	{
		init_nodes_in_b(*stack_a, stack_b);
		move_b_to_a(stack_a, &stack_b);
	}
	set_index(*stack_a);
	check_min_on_top(stack_a);
}
