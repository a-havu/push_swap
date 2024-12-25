/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:01:21 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/25 12:21:58 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "../ft_printf/libftprintf.h"

char     **check_args(int argc, char **argv);
void    push_swap(int argc, char **argv);
void    sa(t_list **lst);

#endif