/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:32:13 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/11 16:34:03 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	hex_low[] = "0123456789abcdef";
char	hex_upp[] = "0123456789ABCDEF";

int	ft_puthex(unsigned int num, char c)
{
	int len;

	len = 0;
	if (num >= 16)
		ft_puthex(num / 16, c);
	if (c == 'x')
		len += ft_putchar_fd(hex_low[num % 16], 1);
	else if (c == 'X')
		len += ft_putchar_fd(hex_upp[num % 16], 1);
	return (len);
}
// int main()
// {
// 	ft_puthex(561561, 'X');
// 	ft_putchar_fd('\n', 1);
// 	ft_puthex(561561, 'x');
// 	return 0;
// }
