/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:25:56 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/21 09:54:13 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	ui;

	if (n < 0)
	{
		ui = -n;
		c = '-';
		write(fd, &c, 1);
	}
	else
		ui = n;
	if (ui / 10)
		ft_putnbr_fd(ui / 10, fd);
	c = (ui % 10) + '0';
	write (fd, &c, 1);
}
