/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:39:12 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/20 13:07:25 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list  *tmp;

    tmp = lst;
    if (!lst)
        return (NULL);
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}