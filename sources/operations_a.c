/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:12:12 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/28 10:25:35 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	temp->prev = NULL;
	if (!*stack_a)
	{
		*stack_a = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *stack_a;
		temp->next->prev = temp;
		*stack_a = temp;
	}
	ft_printf("pa\n");
}

void	ra(t_stack **stack_a)
{
	t_stack	*bottom;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	bottom = stack_last(*stack_a);
	bottom->next = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	bottom->next->prev = bottom;
	bottom->next->next = NULL;
	ft_printf("ra\n");
}

void	sa(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a)->next)
		return ;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev->prev = *stack_a;
	(*stack_a)->prev->next = (*stack_a)->next;
	if ((*stack_a)->next)
		(*stack_a)->next->prev = (*stack_a)->prev;
	(*stack_a)->next = (*stack_a)->prev;
	(*stack_a)->prev = NULL;
	ft_printf("sa\n");
}

void	rra(t_stack **stack_a)
{
	t_stack	*bottom;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	bottom = stack_last(*stack_a);
	bottom->prev->next = NULL;
	bottom->next = *stack_a;
	bottom->prev = NULL;
	*stack_a = bottom;
	bottom->next->prev = bottom;
	ft_printf("rra\n");
}
