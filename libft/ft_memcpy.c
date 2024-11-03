/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:44:20 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/03 17:00:24 by abenajib         ###   ########.fr       */
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
//test overlapping
/*
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
	char s[] = "zxcvbnm";
	char *d = (s + 2);
	printf("C_memmove   - %s\n", memmove(d, s, 4));

	char s1[] = "zxcvbnm";
	char *d1 = (s + 2);
	printf("ft_memmove  - %s\n", ft_memmove(d1, s1, 4));
	printf("------------------------\n");

	char s3[] = "zxcvbnm";
	char *d3 = (s3 + 2);
	printf("C_memcpy   - %s\n", ft_memcpy(d3, s3, 4));

	char s4[] = "zxcvbnm";
	char *d4 = (s4 + 2);
	printf("ft_memcpy  - %s\n", ft_memcpy(d4, s4, 4));
	return 0;
}*/
