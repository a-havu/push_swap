/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:50:46 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/30 16:41:41 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*bottom;

	if (!*stack || !(*stack)->next)
		return ;
	bottom = stack_last(*stack);
	bottom->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	bottom->next->prev = bottom;
	bottom->next->next = NULL;
}

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*bottom;

	if (!(*stack) || !(*stack)->next)
		return ;
	bottom = stack_last(*stack);
	bottom->prev->next = NULL;
	bottom->next = *stack;
	bottom->prev = NULL;
	*stack = bottom;
	bottom->next->prev = bottom;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
