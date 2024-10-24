
#include "libft.h"

size_t strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t dlen;
    size_t slen;
    size_t n;
    size_t i;

    dlen = ft_strlen(dst);
    slen = ft_strlen(src);
    
    if (dstsize == 0)
        return (slen);
    if (dstsize <= dlen)
        return (dstsize + slen);
    n = dstsize - dlen - 1;
    i = 0;
    if (n < slen)
        return (dlen + slen);
    while (i < n && src[i])
        dst[dlen + i] = src[i++];
    dst[dlen + i] = '\0';
    return (dlen + slen);
}
