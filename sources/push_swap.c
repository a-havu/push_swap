/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:00:33 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/16 08:52:57 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_stack(char **argv, t_stack *stack_a)
{
	int	i;
	int	num;

	if (ft_isdigit(argv[0][0]))
		i = 0;
	else
		i = 1;
	while(argv[i])
	{
		num = ft_atoi(argv[i]);
		add_node_bottom(&stack_a, stack_new(num));
		i++;
	}
	stack_last(stack_a)->next = NULL;
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	stack_a = NULL;
	if (argc < 2 || !check_args(argc, argv))
	{
		ft_printf("%s\n", "Error");
		return (-1);
	}
	stack_a = create_stack(argv, stack_a);
	if (!is_stack_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
		{
			sa(&stack_a);
			return (0);
		}
		else if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_big(&stack_a);
	}
	free_stack(stack_a);
}
