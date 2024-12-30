/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:00:33 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/30 12:45:37 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    create_linked_list(char **argv)
{
    t_list *arg_list;
    int i;
    int num;

    arg_list = NULL;
    if (ft_isdigit(argv[0][0]))
        i = 0;
    else
        i = 1;
    num = ft_atoi(argv[i]);
    arg_list = ft_lstnew((void *)&num);
    i++;
    while(argv[i])
    {
        num = ft_atoi(argv[i]);
        ft_lstadd_back(&arg_list, ft_lstnew((void *)&num));
        i++;
    }
    ft_lstlast(arg_list)->next = NULL;
}

void    push_swap(char **argv)
{
    create_linked_list(argv);
}

int main(int argc, char **argv)
{
    if (argc < 2 || !check_args(argc, argv))
    {
        ft_printf("%s\n", "Error");
        return (-1);
    }
    push_swap(argv);
    return (0);
}