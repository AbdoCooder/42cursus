
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));

	substr = malloc(len + 1);
	i = 0;
	if (!substr)
		return (NULL);
	while (i < len && s[start])
	{
		substr[i++] = s[start++];
	}
	substr[i] = '\0';
	return (substr);
}
