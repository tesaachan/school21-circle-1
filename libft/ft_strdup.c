/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:34:52 by georgy            #+#    #+#             */
/*   Updated: 2021/11/14 01:46:05 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s2 = (unsigned char *)malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (*s1)
	{
		s2[i++] = *s1++;
	}
	s2[i] = '\0';
	return ((char *)s2);
}
