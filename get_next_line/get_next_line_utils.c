/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:36:02 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/14 17:01:52 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd)
{
	int		byteread;
	char	c;
	char	*str_buffer;
	int		i;

	str_buffer = (char *)malloc(BUFFER_SIZE);
	if (!str_buffer)
		return (NULL);
	i = 0;
	byteread = read(fd, &c, 1);
	while (byteread > 0)
	{
		str_buffer[i] = c;
		i++;
		if (c == '\n' || c == '\0')
			break ;
		byteread = read(fd, &c, 1);
	}
	if (i == 0 || byteread < 0)
	{
		free(str_buffer);
		return (NULL);
	}
	str_buffer[i] = '\0';
	return (str_buffer);
}
