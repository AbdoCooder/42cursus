/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:20:46 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/15 22:47:51 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_join(int fd, char **buffer, char *additional)
{
	ssize_t	bytesread;
	char	*temp;

	bytesread = read(fd, additional, BUFFER_SIZE);
	if (bytesread <= 0)
	{
		free(additional);
		return (NULL);
	}
	additional[bytesread] = '\0';
	temp = *buffer;
	*buffer = ft_strjoin(*buffer, additional);
	free(temp);
	return (*buffer);
}

static char	*process_line(char **buffer, ssize_t newline)
{
	char	*line;
	char	*temp;

	line = ft_substr(*buffer, 0, newline + 1);
	temp = *buffer;
	*buffer = ft_update_buffer(*buffer, newline);
	free(temp);
	return (line);
}

static char	*handle_eof_case(char **buffer, char *additional)
{
	char	*line;

	free(additional);
	if (*buffer && **buffer)
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (line);
	}
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*additional;
	ssize_t		newline;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	additional = malloc(BUFFER_SIZE + 1);
	if (!additional)
		return (NULL);
	newline = ft_find_newline(buffer);
	while (newline == -1)
	{
		buffer = read_and_join(fd, &buffer, additional);
		if (!buffer)
			return (handle_eof_case(&buffer, additional));
		newline = ft_find_newline(buffer);
	}
	free(additional);
	return (process_line(&buffer, newline));
}
