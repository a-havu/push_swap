/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:50:09 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/23 09:17:33 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sb(t_list **stack_b)
{
    t_list  *temp;
    
    if (!*stack_b || ft_lstsize(*stack_b) == 1)
        return ;
    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = (*stack_b)->next;
    (*stack_b)->next = temp;
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list  *temp;

    if (!*stack_b)
        return ;
    temp = *stack_b;
    ft_lstadd_front(stack_a, temp);
    *stack_b = (*stack_b)->next;
}