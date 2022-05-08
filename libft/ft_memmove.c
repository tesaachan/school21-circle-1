/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:34:26 by georgy            #+#    #+#             */
/*   Updated: 2021/11/11 15:36:47 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp_d;
	char	*temp_s;

	temp_d = (char *)dst;
	temp_s = (char *)src;
	if (!dst && !src)
	{
		return ((void *)0);
	}
	if (dst < src)
	{
		while (len--)
			*temp_d++ = *temp_s++;
	}
	else
	{
		temp_d += len - 1;
		temp_s += len - 1;
		while (len--)
			*temp_d-- = *temp_s--;
	}
	return (dst);
}
