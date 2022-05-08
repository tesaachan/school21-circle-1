/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:24:11 by georgy            #+#    #+#             */
/*   Updated: 2022/01/21 16:24:14 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_negative_int(int *dec)
{
	int	*tmp;

	tmp = dec;
	if (*dec < 0)
	{
		write(1, "-", 1);
		*tmp = *tmp * (-1);
		return (1);
	}
	return (0);
}

int	ft_unsigned_int(unsigned int dec)
{
	int		count;
	char	digit;

	count = 0;
	if (dec >= 10)
	{
		digit = '0' + (dec % 10);
		count += ft_unsigned_int(dec / 10) + write(1, &digit, 1);
	}
	else
	{
		digit = '0' + dec;
		count += write(1, &digit, 1);
	}
	return (count);
}

int	ft_int(int dec)
{
	char	digit;
	int		count;

	count = 0;
	if (dec == -2147483648)
	{
		count = write(1, "-2147483648", 11);
		return (count);
	}
	if (dec < 0)
		count = ft_negative_int(&dec);
	if (dec >= 10)
	{
		digit = '0' + (dec % 10);
		count += ft_int(dec / 10) + write(1, &digit, 1);
	}
	else
	{
		digit = '0' + dec;
		count += write(1, &digit, 1);
	}
	return (count);
}
