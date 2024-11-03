/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:48:53 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/03 17:01:30 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
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
