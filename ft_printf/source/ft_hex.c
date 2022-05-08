/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:07:55 by georgy            #+#    #+#             */
/*   Updated: 2022/01/21 15:53:17 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_hex(unsigned int dec, char c)
{
	int		count;
	char	*base;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (dec >= 16)
		count += ft_hex((dec / 16), c) + write(1, &base[dec % 16], 1);
	else
		count += write(1, &base[dec], 1);
	return (count);
}

int	ft_hex_p(unsigned long dec)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (dec < 0)
		return (0);
	if (dec < 16)
		count += write(1, &base[dec], 1);
	else
		count += ft_hex_p(dec / 16) + write(1, &base[dec % 16], 1);
	return (count);
}
