/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:35:08 by georgy            #+#    #+#             */
/*   Updated: 2021/11/14 01:48:28 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (*haystack && i < len)
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
		{
			if (ft_strlen(needle) + i > len)
				return (NULL);
			return ((char *)haystack);
		}
		haystack++;
		i++;
	}
	return (NULL);
}
