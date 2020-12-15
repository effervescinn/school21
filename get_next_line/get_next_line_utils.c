/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:33:47 by lnorcros          #+#    #+#             */
/*   Updated: 2020/12/15 17:33:49 by lnorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char			*new_s;
	unsigned char	new_c;

	new_s = (char*)s;
	new_c = (unsigned char)c;
	while (*new_s)
	{
		if (*new_s == new_c)
			return (new_s);
		new_s++;
	}
	if (*new_s == '\0' && new_c == '\0')
		return (new_s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res_str;
	size_t	s1_len;
	size_t	s2_len;
	int		i;
	int		j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(res_str = (char*)malloc((s1_len + s2_len + 1) * sizeof(*s1))))
		return (NULL);
	while (s1[i])
	{
		res_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res_str[i] = s2[j];
		i++;
		j++;
	}
	res_str[i] = '\0';
	return (res_str);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	if ((ptr = (char *)malloc(ft_strlen(s1) * sizeof(*s1) + sizeof(*s1))))
	{
		i = 0;
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}

void	ft_strcpy(char *dst, const char *src)
{
	if (*src == '\0')
		*dst = '\0';
	else
	{
		while (*src)
		{
			*dst = *src;
			dst++;
			src++;
		}
		while (*dst)
		{
			*dst = '\0';
		}
	}
}
