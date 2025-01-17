/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:41:57 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/16 08:47:54 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_node_bottom(t_stack **stack, t_stack *new_node)
{
	t_stack  *last;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = stack_last(*stack);
	last->next = new_node;
}

void	add_node_top(t_stack **stack, t_stack *new_node)
{
	if (new_node)
	{
		new_node->next = *stack;
		*stack = new_node;
	}
}

t_stack	*stack_new(int num)
{
	t_stack  *new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = num;
	new_node->next = NULL;

	return (new_node);
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack  *tmp;

	tmp = stack;
	if (!stack)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		size;
    
	size = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}