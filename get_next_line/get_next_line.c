/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:20:46 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/17 15:34:26 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*lineset(char *line)
{
	char	*left;
	ssize_t	i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	left = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (!left)
		return (NULL);
	if (!(*left))
	{
		free(left);
		left = NULL;
	}
	line[i + 1] = '\0';
	return (left);
}

static char	*extract_line(int fd, char *staticbuffer, char *buffer)
{
	ssize_t	bytesread;
	char	*tmp;

	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(staticbuffer);
			return (NULL);
		}
		else if (bytesread == 0)
			break ;
		buffer[bytesread] = '\0';
		if (!staticbuffer)
			staticbuffer = ft_strdup("");
		tmp = staticbuffer;
		staticbuffer = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (staticbuffer);
}

char	*get_next_line(int fd)
{
	static char	*staticbuffer;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(staticbuffer);
		free(buffer);
		staticbuffer = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = extract_line(fd, staticbuffer, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	staticbuffer = lineset(line);
	return (line);
}
