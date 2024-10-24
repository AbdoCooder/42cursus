
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	totaleSize;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	totaleSize = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(totaleSize);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i++] = s1[i];
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}
