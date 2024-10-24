
#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	size_t	totaleSize;
	void	*ptr;

	totaleSize = nmemb * size;
	if (totaleSize == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (totaleSize / nmemb != size)
		return (NULL);
	ptr = malloc(totaleSize);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, totaleSize);
	return (ptr);
}
