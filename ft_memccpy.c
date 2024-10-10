//	dest: 	A pointer to the memory location
//			where the copied data will be stored.
//	src	: 	A pointer to the memory location
//			from where the data is to be copied.
//	n	: 	The number of bytes to be copied.
//	c	:	The char that we will stop copying in we found it into src

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*psrc;
	unsigned char	*pdest;

	psrc = (unsigned char *)src;
	pdest = (unsigned char *)dest;
	while (n--)
	{
		*pdest = *psrc;
		if (*psrc == (unsigned char)c)
			return (++pdest);
		pdest++;
		psrc++;
	}
	return (NULL);
}
