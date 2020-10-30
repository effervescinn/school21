#include <stdio.h>
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memset(void *b, int c, size_t len);
size_t  ft_strlen(const char *str);
void *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
void *ft_memmove(void *dst, const void *src, size_t len);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);