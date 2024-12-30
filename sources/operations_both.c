/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:50:46 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/28 10:46:46 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    del(t_list *content)
{
    free(content);
}

void    ss(t_list **stack_a, t_list **stack_b)
{
    sa(*stack_a);
    sb(*stack_b);
    ft_printf("%s\n", "ss");
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    ra(*stack_a);
    rb(*stack_b);
    ft_printf("%s\n", "rr");
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    ft_printf("%s\n", "rrr");
}