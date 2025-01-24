/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:41:57 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/23 15:48:12 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_node_top(t_stack **stack, t_stack *new_node)
{
	if (new_node)
	{
		new_node->next = *stack;
		*stack = new_node;
	}
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;
    
	size = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}