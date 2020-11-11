/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:46:50 by lnorcros          #+#    #+#             */
/*   Updated: 2020/11/11 13:46:51 by lnorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	char		*ptr_substr;
	const char	*ptr_s;

	ptr_s = s;
	if ((substr = (char *)malloc((len + 1) * sizeof(*ptr_s))) && (s != NULL))
	{
		ptr_substr = substr;
		if (ft_strlen(s) <= start)
		{
			*substr = '\0';
			return (substr);
		}
		ptr_s = ptr_s + start;
		while (*ptr_s && len--)
		{
			*ptr_substr = *ptr_s;
			ptr_substr++;
			ptr_s++;
		}
		*ptr_substr = '\0';
		return (substr);
	}
	return (NULL);
}
