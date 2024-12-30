/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:10:37 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/21 09:51:07 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	product;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	product = nmemb * size;
	if ((product / size) != nmemb)
		return (NULL);
	ptr = malloc(product);
	if (ptr)
		ft_bzero(ptr, product);
	return (ptr);
}
