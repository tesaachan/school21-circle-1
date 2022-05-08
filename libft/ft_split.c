/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:34:47 by georgy            #+#    #+#             */
/*   Updated: 2021/11/14 04:51:47 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(char const *s, char *c)
{
	size_t	i;
	size_t	size;
	size_t	f;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		f = 0;
		while (s[i] == *c && s[i] != '\0')
			i++;
		while (s[i] != *c && s[i] != '\0')
		{
			f = 1;
			i++;
		}
		if (f)
			size++;
	}
	return (size);
}

static size_t	ft_len(char const *s, char *c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != *c)
		i++;
	return (i);
}

static char	**ft_free_buffer(char **buffer)
{
	size_t	i;

	i = -1;
	while (buffer[++i] != NULL)
		free(buffer[i]);
	free(buffer);
	return (NULL);
}

static char	*ft_fill(char *buffer, char const *s, char *c)
{
	size_t	i;

	i = -1;
	while (s[++i] != '\0' && s[i] != *c)
		buffer[i] = s[i];
	buffer[i] = '\0';
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	buffer = (char **)malloc(sizeof(char *) * (ft_size(s, &c) + 1));
	if (buffer == NULL)
		return (NULL);
	while (s[++i] != '\0')
	{
		if (s[i] != '\0' && s[i] != c)
		{
			buffer[j] = (char *)malloc(sizeof(char) * (ft_len(&s[i], &c) + 1));
			if (buffer[j] == NULL)
				return (ft_free_buffer(buffer));
			buffer[j] = ft_fill(buffer[j], &s[i], &c);
			i += ft_len(&s[i], &c) - 1;
			j++;
		}
	}
	buffer[j] = NULL;
	return (buffer);
}
