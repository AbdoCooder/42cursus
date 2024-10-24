
#include "libft.h"

void *memchr(const void *s, int c, size_t n)
{
    unsigned char *str;
    size_t i;
    
    str = (unsigned char*)s;
    i = 0;
    while (n > 0)
    {
        if (str[i] == (unsigned char)c)
            return (str + i);
        i++;
        n--;
    }
    return (NULL);
}
