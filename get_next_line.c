/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:21:47 by amylle            #+#    #+#             */
/*   Updated: 2024/03/11 17:15:01 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_getline(char *buffer)
{
	char	*nextline;
	char	*line;

	if (!buffer[0])
		return (NULL);
	nextline = ft_strchr(buffer, '\n');
	if (nextline)
		line = ft_substr(buffer, 0, nextline - buffer + 1);
	else
		line = ft_substr(buffer, 0, ft_strlen(buffer) + 1);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_getbuffer(char *buffer)
{
	char	*nextline;
	char	*temp;

	nextline = ft_strchr(buffer, '\n');
	if (nextline)
		temp = ft_substr(nextline + 1, 0, ft_strlen(nextline + 1));
	free (buffer);
	if (!nextline || !temp)
		return (NULL);
	return (temp);
}

char	*read_file(int fd, char *str)
{
	char	*buffer;
	int		readret;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	readret = 1;
	while (!ft_strchr(str, '\n') && readret > 0)
	{
		readret = read(fd, buffer, BUFFER_SIZE);
		if (readret == -1)
		{
			free (buffer);
			free (str);
			return (NULL);
		}
		buffer[readret] = 0;
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	buffer = ft_getbuffer(buffer);
	return (line);
}
