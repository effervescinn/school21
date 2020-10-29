
#include <stdio.h>
#include <string.h>

void *memccpy(void *dest, const void *src, int c, size_t n)
{
    char			*new_dest;
	const char      *new_src;
    unsigned char	s;

	new_dest = (char*)dest;
	new_src = (const char*)src;
	s = (unsigned char)c;
	while (n && *new_src && *new_dest)
	{
		if (*new_src == s)
			return (new_src);
		*new_dest = *new_src;
		new_src++;
		new_dest++;
		n--;
	}
	return (NULL);
}