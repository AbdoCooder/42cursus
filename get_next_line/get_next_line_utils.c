/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:36:02 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/17 13:29:29 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	i = 0;
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (i < len && s[start])
	{
		substr[i++] = s[start++];
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(const char *src)
{
	int		slen;
	char	*dest;
	int		i;

	slen = 0;
	i = 0;
	while (src[slen])
		slen++;
	dest = (char *)malloc(sizeof(char) * slen + 1);
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	totalesize;
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	totalesize = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(totalesize);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;
	char			character;

	character = (char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == character)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == character)
		return ((char *) &str[i]);
	return (NULL);
}
