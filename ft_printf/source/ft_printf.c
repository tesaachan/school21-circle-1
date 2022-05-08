/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:42:11 by georgy            #+#    #+#             */
/*   Updated: 2022/01/21 16:00:35 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_process(va_list args, char str)
{
	if (str == '%')
		return (write(1, &str, 1));
	else if (str == 'c')
		return (ft_char(va_arg(args, int)));
	else if (str == 'd' || str == 'i')
		return (ft_int(va_arg(args, int)));
	else if (str == 'x' || str == 'X')
		return (ft_hex(va_arg(args, unsigned int), str));
	else if (str == 'p')
		return (write(1, "0x", 2) + ft_hex_p(va_arg(args, unsigned long)));
	else if (str == 's')
		return (ft_string(va_arg(args, char *)));
	else if (str == 'u')
		return (ft_unsigned_int(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_process(args, str[i]);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
