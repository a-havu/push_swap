/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:50:09 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/28 10:48:04 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list  *temp;

    if (!*stack_b)
        return ;
    temp = *stack_b;
    ft_lstadd_front(stack_a, temp);
    *stack_b = (*stack_b)->next;
    ft_printf("%s\n", "pb");
}

void    rb(t_list **stack_b)
{
    t_list  *top;
    t_list  *bottom;

    if (ft_lstsize(stack_b) < 2)
        return ;
    top = *stack_b;
    bottom = ft_lstlast(stack_b);
    ft_lstadd_back(stack_b, top);
    *stack_b = top->next;
    ft_printf("%s\n", "rb");
}

void    sb(t_list **stack_b)
{
    t_list  *temp;
    
    if (!*stack_b || ft_lstsize(*stack_b) == 1)
        return ;
    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = (*stack_b)->next;
    (*stack_b)->next = temp;
    ft_printf("%s\n", "sb");
}

void    rrb(t_list **stack_b)
{
    t_list  *bottom;
    t_list  *new_bottom;
    
    if (ft_lstsize(stack_b) < 2)
        return ;
    bottom = ft_lstlast(stack_b);
    ft_lstadd_front(*stack_b, bottom);
    new_bottom = ft_lstlast(stack_b);
    ft_lstdelone(new_bottom, del);
    ft_printf("%s\n", "rrb");
}