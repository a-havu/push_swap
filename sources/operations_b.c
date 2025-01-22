/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:50:09 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/21 11:30:24 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	ft_printf("%s\n", "pb");
}

void	rb(t_stack **stack_b)
{
	t_stack  *top;
	t_stack  *bottom;

	if (stack_size(*stack_b) < 2)
		return ;
	top = *stack_b;
	bottom = stack_last(*stack_b);
	bottom->next = top;
	*stack_b = top->next;
	ft_printf("%s\n", "rb");
}

void	sb(t_stack **stack_b)
{
	t_stack  *temp;
    
	if (!stack_b || !*stack_b || stack_size(*stack_b) == 1)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	ft_printf("%s\n", "sb");
}

void	rrb(t_stack **stack_b)
{
	t_stack  *bottom;
	t_stack  *second_last;
    
	if (stack_size(*stack_b) < 2)
		return ;
	bottom = stack_last(*stack_b);
	second_last = bottom->prev;
	add_node_top(stack_b, bottom);
	second_last->next = NULL;
	free(bottom);
	ft_printf("%s\n", "rrb");
}