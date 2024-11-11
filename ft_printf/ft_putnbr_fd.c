/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:47:42 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/11 15:40:04 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	len;
	int check;

	len = 0;
	check = 0;
	if (n == -2147483648)
	{
		check = ft_putstr_fd("-2147483648", fd);
		if(check == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		check = ft_putchar_fd('-', fd);
		if(check == -1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		check = ft_putchar_fd(n + '0', fd);
		if(check == -1)
			return (-1);
		len++;
	}
	return (len);
}
