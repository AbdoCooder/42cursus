/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:13:05 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/14 17:09:34 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	return (read_line(fd));
}
#include <stdio.h> //FIXME: remove it before pushing the project
int main(void)
{
	int		fd;
	char	*str;
	int		i;
	fd = open("file.txt", O_RDONLY);
	i = 0;
	while(i < 10)
	{
		printf("call number %d:\n", i);
		str = get_next_line(fd);
		printf("%s\n", str);
		i++;
	}
	return (0);
}
