/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:35:43 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/20 13:02:21 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    t_list  *tmp;
    int     size;
    
    size = 0;
    tmp = lst;
    while (tmp)
    {
        tmp = tmp->next;
        size++;
    }
    return (size);
}