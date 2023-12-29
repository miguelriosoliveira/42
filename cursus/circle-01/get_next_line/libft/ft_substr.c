/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:12 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:12 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;
	int		substr_len;
	int		i;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > str_len)
		len = str_len;
	substr_len = min(start + len, str_len) - start;
	substr = ft_calloc(substr_len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < substr_len)
	{
		substr[i] = s[i + start];
		i++;
	}
	return (substr);
}
