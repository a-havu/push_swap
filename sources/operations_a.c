/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:12:12 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/16 08:49:57 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack  *temp;
    
	if (!stack_b || !*stack_b)
		return ;
	temp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = temp;
	ft_printf("%s\n", "pa");
}

void	ra(t_stack **stack_a)
{
	t_stack  *top;
	t_stack  *bottom;

	if (stack_size(*stack_a) < 2)
		return ;
	top = *stack_a;
	bottom = stack_last(*stack_a);
	bottom->next = top;
	*stack_a = top->next;
	ft_printf("%s\n", "ra");
}

void	sa(t_stack **stack_a)
{
	t_stack	*temp;
    
	if (!*stack_a || !stack_a || stack_size(*stack_a) == 1)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	ft_printf("%s\n", "sa");
}

void	rra(t_stack **stack_a)
{
	t_stack	*bottom;
	t_stack	*second_last;
    
	if (stack_size(*stack_a) < 2)
		return ;
	bottom = stack_last(*stack_a);
	second_last = bottom->prev;
	add_node_top(stack_a, bottom);
	second_last->next = NULL;
	free(bottom);
	ft_printf("%s\n", "rra");
}