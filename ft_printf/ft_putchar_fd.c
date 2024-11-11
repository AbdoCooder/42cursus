/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:10:34 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/11 15:06:16 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar_fd(char c, int fd)
{
	int len;
	len = write(fd, &c, 1);
	if (len == -1)
		return (-1);
	return (1);
}
