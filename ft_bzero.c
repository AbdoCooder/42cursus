/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:33:19 by abenajib            #+#    #+#           */
/*   Updated: 2024/09/24 20:33:19 by abenajib           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *ptr, int x, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)ptr;
	while (*str && n > 0)
	{
		*str = (unsigned char)x;
		n--;
		str++;
	}
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
