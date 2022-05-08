/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:34:34 by georgy            #+#    #+#             */
/*   Updated: 2021/11/11 16:30:00 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long long n, int fd)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write(fd, &c, 1);
		return ;
	}
	ft_putnbr(n / 10, fd);
	ft_putnbr(n % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	lo;

	lo = n;
	if (lo < 0)
	{
		lo *= -1;
		write(fd, "-", 1);
	}
	ft_putnbr(lo, fd);
}
