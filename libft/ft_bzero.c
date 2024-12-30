/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:11:08 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/21 09:50:57 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*new_ptr;
	size_t			i;

	i = 0;
	new_ptr = (unsigned char *)s;
	while (i < n)
	{
		new_ptr[i] = '\0';
		i++;
	}
}
