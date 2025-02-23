/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:01:21 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/31 13:11:55 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_plus.h"
# include "libftprintf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	long			value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest_in_stack;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
}	t_stack;

//          CHECKING THE ARGUMENTS
int		arg_is_number(char *arg);
int		find_duplicate(char **argv, int i);
void	free_everything(char **arg);
void	ft_error(void);
int		int_ok(char *arg);
char	**split_args(char *arg);
char	**check_args(char **argv);

//          STACK
t_stack	*biggest_value(t_stack *stack);
t_stack	*smallest_value(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);
void	free_stack(t_stack *stack);
void	set_index(t_stack *stack);

//          ALGORITHM
t_stack	*find_cheapest_node(t_stack *stack);
void	init_nodes_in_a(t_stack *stack_a, t_stack *stack_b);
void	init_nodes_in_b(t_stack *stack_a, t_stack *stack_b);
int		is_stack_sorted(t_stack *stack_a);
void	sort_big(t_stack **stack_a);
void	sort_three(t_stack **stack_a);

//          MOVES
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	sa(t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_b);
void	sb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif