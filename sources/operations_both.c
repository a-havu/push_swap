/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:50:46 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/08 13:50:43 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void    del(void *content)
{
    free(content);
}

void    ss(t_list **stack_a, t_list **stack_b)
{
    sa(stack_a);
    sb(stack_b);
    ft_printf("%s\n", "ss");
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    ft_printf("%s\n", "rr");
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    ft_printf("%s\n", "rrr");
}