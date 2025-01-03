/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:18:30 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/21 18:53:03 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	readstatic(ssize_t *bytesread, int fd, char **tmp, char **sbuff)
{
	*bytesread = read(fd, *tmp, BUFFER_SIZE);
	if (*bytesread <= 0)
	{
		free(*tmp);
		if (*bytesread == 0)
			return ;
		free(*sbuff);
		*sbuff = NULL;
		return ;
	}
}

void	read_join(int fd, char **sbuff)
{
	char	*tmp;
	char	*tmp2;
	ssize_t	bytesread;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
	{
		free(*sbuff);
		*sbuff = NULL;
		return ;
	}
	bytesread = 1;
	while (bytesread > 0 && ft_strlen(*sbuff, '\n') == -1)
	{
		readstatic(&bytesread, fd, &tmp, sbuff);
		if (bytesread <= 0)
			return ;
		tmp[bytesread] = '\0';
		tmp2 = *sbuff;
		*sbuff = ft_strjoin(*sbuff, tmp);
		free(tmp2);
	}
	free(tmp);
}

char	*get_next_line(int fd)
{
	static char	*sbuff[10240];
	char		*line;
	char		*tmp2;
	ssize_t		num;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (free(sbuff[fd]), sbuff[fd] = NULL, NULL);
	if (ft_strlen(sbuff[fd], '\n') == -1)
		read_join(fd, &sbuff[fd]);
	line = ft_substr(sbuff[fd], 0, ft_strlen2(sbuff[fd], '\n') + 1);
	if (!line)
		return (free(line), free(sbuff[fd]), sbuff[fd] = NULL, NULL);
	tmp2 = sbuff[fd];
	num = ft_strlen2(sbuff[fd], '\n') + 1;
	sbuff[fd] = ft_substr(sbuff[fd], num, ft_strlen2(sbuff[fd], '\0'));
	free(tmp2);
	return (line);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int fd = open("file.txt", O_RDWR);
// 	if (fd < 0)
// 		exit(1);
// 	int fd2 = open("file2.txt", O_RDWR);
// 	if (fd2 < 0)
// 		exit(1);
// 	printf("fd1: %s",get_next_line(fd));
// 	printf("fd2: %s",get_next_line(fd2));

// 	close(fd);
// 	close(fd2);
// 	return (0);
// }
