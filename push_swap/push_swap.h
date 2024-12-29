/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:01:21 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/28 10:48:30 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/libftprintf.h"

void    push_swap(int argc, char **argv);
char     **check_args(int argc, char **argv);
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