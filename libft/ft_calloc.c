/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:33:43 by georgy            #+#    #+#             */
/*   Updated: 2021/11/11 15:33:44 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = (unsigned char *)malloc(count * size);
	if (mem == (void *)0)
		return ((void *)0);
	while (i != count * size)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}
