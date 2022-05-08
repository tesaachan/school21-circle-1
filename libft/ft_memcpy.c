/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:34:23 by georgy            #+#    #+#             */
/*   Updated: 2021/11/11 15:34:24 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"
#include "stdio.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp;

	temp = dst;
	if (!dst && !src)
	{
		return ((void *)0);
	}
	while (n--)
	{
		*temp++ = *(char *)src++;
	}
	return (dst);
}
