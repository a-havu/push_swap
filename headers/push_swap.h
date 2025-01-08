/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:01:21 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/08 13:50:24 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libftprintf.h"
# include <limits.h>

void    push_swap(char **argv);
char    **args_split(char *arg);
char    **check_args(int argc, char **argv);
void    del(void *content);

//          MOVES
void    pa(t_list **stack_a, t_list **stack_b);
void    ra(t_list **stack_a);
void    sa(t_list **stack_a);
void    pb(t_list **stack_a, t_list **stack_b);
void    rb(t_list **stack_b);
void    sb(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);
void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);

#endif