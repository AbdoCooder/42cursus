// ptr ==> Starting address of memory to be filled
// x   ==> Value to be filled
// n   ==> Number of bytes to be filled starting from ptr to be filled
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
/*
// C program to demonstrate working of ft_memset()
#include <stdio.h>
#include <string.h>

int main()
{
	char	str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore ft_memset(): %s\n", str);

	ft_memset(str + 13, '.', 300*sizeof(char));

	printf("After  ft_memset(): %s\n", str);
	return 0;
}
*/
