/*	dest: 	A pointer to the memory location
			where the copied data will be stored.
	src	: 	A pointer to the memory location
			from where the data is to be copied.
	n	: 	The number of bytes to be copied.*/

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*psrc;
	unsigned char	*pdest;

	psrc = (unsigned char *)src;
	pdest = (unsigned char *)dest;
	while (n--)
		*pdest++ = *psrc++;
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "Geeks";
	char str2[] = "Quiz";

	puts("str1 before memcpy ");
	puts(str1);

	ft_memcpy(str1, str2, sizeof(str2));

	puts("\nstr1 after memcpy ");
	puts(str1);

	return (0);
}
*/
