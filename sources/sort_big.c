/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:17:43 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/16 10:02:54 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_big(t_stack **stack_a)
{
	t_stack	**stack_b;
	int		stack_len;

	stack_len = stack_size(stack_a);
	if (stack_len-- > 3 && !is_stack_sorted(stack_a))
		pb(stack_a, stack_b);
	if (stack_len-- > 3 && !is_stack_sorted(stack_a))
		pb(stack_a, stack_b);
	while (stack_size(stack_a) > 3)
	{
		init_nodes_in_a(stack_a, stack_b);
	}
	sort_three(stack_a);
    
}