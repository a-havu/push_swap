/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:50:09 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/30 16:41:38 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	temp->prev = NULL;
	if (!*stack_b)
	{
		*stack_b = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *stack_b;
		temp->next->prev = temp;
		*stack_b = temp;
	}
	ft_printf("pb\n");
}

void	rb(t_stack **stack_b)
{
	t_stack	*bottom;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	bottom = stack_last(*stack_b);
	bottom->next = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	bottom->next->prev = bottom;
	bottom->next->next = NULL;
	ft_printf("rb\n");
}

void	sb(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b)->next)
		return ;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev->prev = *stack_b;
	(*stack_b)->prev->next = (*stack_b)->next;
	if ((*stack_b)->next)
		(*stack_b)->next->prev = (*stack_b)->prev;
	(*stack_b)->next = (*stack_b)->prev;
	(*stack_b)->prev = NULL;
	ft_printf("sb\n");
}

void	rrb(t_stack **stack_b)
{
	t_stack	*bottom;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	bottom = stack_last(*stack_b);
	bottom->prev->next = NULL;
	bottom->next = *stack_b;
	bottom->prev = NULL;
	*stack_b = bottom;
	bottom->next->prev = bottom;
	ft_printf("rrb\n");
}
