/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:35:10 by georgy            #+#    #+#             */
/*   Updated: 2021/11/14 22:23:11 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	c_char;

	temp = (char *)s;
	c_char = (char)c;
	while (*temp)
	{
		temp++;
	}
	while (temp != s - 1)
	{
		if (*temp == c_char)
		{
			return ((char *)temp);
		}
		temp--;
	}
	return (NULL);
}
