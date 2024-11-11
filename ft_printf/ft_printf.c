/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:15:44 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/11 16:07:58 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

// va_list args: This declares a variable args that will be used to access the variadic arguments.

// va_start(args, count): This macro initializes args to retrieve the additional arguments.
//						The first parameter is the va_list variable, and the second parameter is
//						the last named parameter before the (...).

// va_arg(args, int): This macro retrieves the next argument in the list.
//					The type of the argument must be specified (in this case, int).

// va_end(args): This macro cleans up the va_list variable.

int	ft_printf(const char *str, ...)
{
	int		printed;
	va_list	args;

	va_start(args, str);
	printed = 0;
	if (write (1, "", 0) == -1)
		return (-1);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
		else
		{

		}
	}
	va_end(args);
	return (printed);
}
#include <stdio.h>

int	main()
{
	return (ft_printf("\t", 5));
}
