/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:00:33 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/31 10:43:06 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	int	i;

	i = stack->value;
	while (stack)
	{
		if (i > stack->value)
			return (0);
		i = stack->value;
		stack = stack->next;
	}
	return (1);
}

static void	add_node(t_stack **stack_a, int num)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = num;
	if (!(*stack_a))
	{
		*stack_a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = stack_last(*stack_a);
		last_node->next = node;
		node->prev = last_node;
	}
}

static void	create_stack(char **argv, t_stack **stack_a)
{
	int		i;
	int		num;

	if (ft_isdigit(argv[0][0]) || (argv[0][0] == '-' && ft_isdigit(argv[0][1]))
		|| (argv[0][0] == '+' && ft_isdigit(argv[0][1])))
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		add_node(stack_a, num);
		i++;
	}
}

static void	handle_arguments(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		argv = split_args(argv[1]);
		if (!argv)
			ft_error();
		create_stack(argv, stack_a);
		free_everything(argv);
	}
	else
	{
		argv = check_args(argv);
		if (!argv)
			ft_error();
		create_stack(argv, stack_a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	handle_arguments(argc, argv, &stack_a);
	if (!is_stack_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(&stack_a);
		else if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_big(&stack_a);
	}
	free_stack(stack_a);
}
