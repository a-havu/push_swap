/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:01:21 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/16 16:13:49 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_plus/libft_src/libft_plus.h"
# include "libft_plus/ft_printf/libftprintf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
}	t_stack;


//          CHECKING THE ARGUMENTS
int		arg_is_number(char *arg);
int		find_duplicate(char **argv, int i);
int		int_ok(char *arg);
char	**split_args(char *arg);
char	**check_args(int argc, char **argv);

//          STACK
void	add_node_bottom(t_stack **stack, t_stack *new_node);
void	add_node_top(t_stack **stack, t_stack *new_node);
int		is_stack_sorted(t_stack *stack_a);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_new(int num);
int		stack_size(t_stack *stack);
void	sort_three(t_stack **stack_a);
void	free_stack(t_stack *stack);

//          ALGORITHM
void	sort_big(t_stack **stack_a);
void	init_nodes_in_a(t_stack **stack_a, t_stack **stack_b);

//          MOVES
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	sa(t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_b);
void	sb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif