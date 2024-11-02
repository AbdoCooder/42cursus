/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:44:20 by abenajib          #+#    #+#             */
/*   Updated: 2024/10/31 10:39:45 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*psrc;
	unsigned char	*pdest;

	if (!dest && !src)
		return (NULL);
	psrc = (unsigned char *)src;
	pdest = (unsigned char *)dest;
	while (n--)
		*pdest++ = *psrc++;
	return (dest);
}
