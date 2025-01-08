/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:12:12 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/08 13:50:59 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list  *temp;
    
    if (!stack_a || !*stack_a)
        return ;
    temp = *stack_a;
    ft_lstadd_front(stack_b, temp);
    *stack_a = (*stack_a)->next;
    ft_printf("%s\n", "pa");
}

void    ra(t_list **stack_a)
{
    t_list  *top;
    t_list  *bottom;

    if (ft_lstsize(*stack_a) < 2)
        return ;
    top = *stack_a;
    bottom = ft_lstlast(*stack_a);
    ft_lstadd_back(stack_a, top);
    *stack_a = top->next;
    ft_printf("%s\n", "ra");
}

void    sa(t_list **stack_a)
{
    t_list  *temp;
    
    if (!*stack_a || ft_lstsize(*stack_a) == 1)
        return ;
    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = (*stack_a)->next;
    (*stack_a)->next = temp;
    ft_printf("%s\n", "sa");
}

void    rra(t_list **stack_a)
{
    t_list  *bottom;
    t_list  *new_bottom;
    
    if (ft_lstsize(*stack_a) < 2)
        return ;
    bottom = ft_lstlast(*stack_a);
    ft_lstadd_front(stack_a, bottom);
    new_bottom = ft_lstlast(*stack_a);
    ft_lstdelone(new_bottom, &del);
    ft_printf("%s\n", "rra");
}