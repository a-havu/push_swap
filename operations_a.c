/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:12:12 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/22 10:21:49 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_list **stack_a)
{
    t_list *tmp;
    
    if (!*stack_a || ft_lstsize(*stack_a) == 1)
        return ;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = (*stack_a)->next;
    (*stack_a)->next = tmp;
}
void    pa(t_list **stack_a, t_list **stack_b)
{
    if (!*stack_a)
        return ;
    ft_lstadd_front(*stack_b, stack_a);
    ft_lstdelone(stack_a, *del);
}