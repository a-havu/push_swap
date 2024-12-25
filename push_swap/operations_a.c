/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:12:12 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/23 09:43:27 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_list **stack_a)
{
    t_list  *temp;
    
    if (!*stack_a || ft_lstsize(*stack_a) == 1)
        return ;
    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = (*stack_a)->next;
    (*stack_a)->next = temp;
}

void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list  *temp;
    
    if (!*stack_a)
        return ;
    temp = *stack_a;
    ft_lstadd_front(stack_b, temp);
    *stack_a = (*stack_a)->next;
}

void    ra(t_list **stack_a)
{
    t_list  *top;
    t_list  *bottom;

    if (ft_lstsize(stack_a) < 2)
        return ;
    top = *stack_a;
    bottom = ft_lstlast(stack_a);
    ft_lstadd_back(stack_a, top);
    *stack_a = top->next;
}