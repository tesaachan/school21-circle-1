/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:48:50 by akami             #+#    #+#             */
/*   Updated: 2022/01/19 22:48:52 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_read(int fd, char *buf, char **str)
{
	size_t	i;
	char	*tmp;

	if (!(str[fd]) || !ft_strchr(str[fd], '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		while (i)
		{
			buf[i] = '\0';
			if (!(str[fd]))
				str[fd] = ft_substr(buf, 0, i);
			else
			{
				tmp = str[fd];
				str[fd] = ft_strjoin(str[fd], buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(fd, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

static char	*ft_getline(int fd, char **str)
{
	size_t	i;
	size_t	j;
	char	*line;
	char	*line_end;
	char	*tmp;

	line_end = ft_strchr(str[fd], '\n');
	if (!line_end)
	{
		line = ft_substr(str[fd], 0, ft_strlen(str[fd]));
		free(str[fd]);
		str[fd] = NULL;
		return (line);
	}
	i = ft_strlen(str[fd]);
	j = ft_strlen(line_end);
	line = ft_substr(str[fd], 0, i - j + 1);
	tmp = str[fd];
	str[fd] = ft_substr(line_end, 1, j - 1);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str[OPEN_MAX];

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (NULL);
	}
	ft_read(fd, buf, str);
	if (!str[fd])
		return (NULL);
	if (ft_strlen(str[fd]) == 0)
	{
		free(str[fd]);
		return (NULL);
	}
	return (ft_getline(fd, str));
}
