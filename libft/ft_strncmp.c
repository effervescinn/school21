#include "libft.h"
#include <string.h>
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char *new_s1;
	unsigned const char *new_s2;

	new_s1 = (unsigned const char*)s1;
	new_s2 = (unsigned const char*)s2;
	if (n == 0)
		return (0);
	while (*new_s1 != '\0' && *new_s2 != '\0' && *new_s1 == *new_s2 && n > 1)
	{
		new_s1++;
		new_s2++;
		n--;
	}
	if (*new_s1 == *new_s2)
		return (0);
	else
		return (*new_s1 - *new_s2);
}

// int main() {
// 	printf("%d\n", strncmp("abcdefgh", "", 0));
// 	return 0;
// }