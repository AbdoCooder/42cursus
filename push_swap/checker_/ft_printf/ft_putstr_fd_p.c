/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:34:01 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/17 21:48:00 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_putstr_fd_p(char *s, int fd)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (*s)
	{
		ft_putchar_fd_p(*s, fd);
		s++;
		len++;
	}
	return (len);
}
// #include <stdio.h>
// int main()
// {
// 	int n = ft_putstr_fd("helosdjsmcdsc", 1);
// 	printf("\n%d\n", n);
// }