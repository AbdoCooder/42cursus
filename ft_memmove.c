/**
 * ft_memmove - Copies 'n' bytes from memory area 'src' to memory area 'dest'.
 *				The memory areas may overlap: copying is done in a safe manner.
 *
 * @dest: The destination memory area.
 * @src: The source memory area.
 * @n: The number of bytes to copy.
 *
 * The function handles overlapping memory by determining whether to copy
 * forwards or backwards:
 * - If the destination is after the source in memory, it copies backwards
 *   to prevent overwriting the source before copying is done.
 * - Otherwise, it copies forwards.
 *
 * Return: A pointer to the destination memory area 'dest'.
 */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char)dest;
	s = (unsigned char)src;
	if (d == s || n == 0)
	{
		return (dest);
	}
	if (d > s)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	else
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	return (dest);
}
