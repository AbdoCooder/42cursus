/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:47:42 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/12 13:33:53 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_numsize(unsigned int num)
{
	int	count;

	count = 0;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_putunint_fd(unsigned int nb, int fd)
{
	unsigned int	n;

	n = nb;
	if (n > 9)
	{
		ft_putunint_fd(n / 10, fd);
		ft_putunint_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
	return (ft_numsize(nb));
}
// #include <stdio.h>
// int main()
// {
// 	int n = ft_putunint_fd(524525252, 1);
// 	printf("\n%d\n", n);
// }