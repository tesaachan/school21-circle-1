/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:34:50 by georgy            #+#    #+#             */
/*   Updated: 2021/11/14 22:18:07 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_char;
	char	*temp;

	c_char = (char)c;
	temp = (char *)s;
	while (*temp)
	{
		if (*temp == c_char)
			return (temp);
		temp++;
	}
	if (c_char == '\0')
		return (temp);
	return (NULL);
}
