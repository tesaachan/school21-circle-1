/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:35:12 by georgy            #+#    #+#             */
/*   Updated: 2021/11/14 01:54:38 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	cnt;

	len = 0;
	while (*s1)
	{
		i = 0;
		cnt = ft_strlen(set);
		while (set[i])
		{
			if (set[i] != *s1)
			{
				cnt--;
			}
			i++;
		}
		if (cnt == 0)
			return (len);
		len++;
		s1++;
	}
	return (len);
}

static int	ft_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	cnt;

	len = ft_strlen(s1);
	s1 = s1 + ft_strlen(s1) - 1;
	while (len--)
	{
		i = 0;
		cnt = ft_strlen(set);
		while (set[i])
		{
			if (set[i] != *s1)
			{
				cnt--;
			}
			i++;
		}
		if (cnt == 0)
			return (len);
		s1--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (s1 == NULL || set == NULL)
	{
		return (NULL);
	}
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start == -1 || end == -1)
	{
		str = (char *)malloc(1 * sizeof(char));
		*str = '\0';
		return (str);
	}
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
