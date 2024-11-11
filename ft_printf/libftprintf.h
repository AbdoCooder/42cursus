/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:06:30 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/11 15:37:25 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putstr_fd(char *s, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);

# endif
