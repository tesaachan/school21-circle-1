/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:33:56 by georgy            #+#    #+#             */
/*   Updated: 2021/11/11 16:59:34 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int num)
{
	long	n;
	long	len;

	n = num;
	len = 1;
	if (n < 0)
	{
		len++;
		n = -1 * n;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		negative;
	char	*str;
	long	numlen;
	long	num;

	negative = -1;
	numlen = ft_numlen(n);
	str = (char *)malloc((numlen + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[numlen] = '\0';
	if (n < 0)
	{
		negative = 0;
		str[0] = '-';
	}
	num = n;
	if (negative == 0)
		num = -1 * num;
	while (--numlen != negative)
	{
		str[numlen] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
