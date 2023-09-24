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
	int		i;
	int		start_int;
	int		size;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_calloc(1, sizeof(char)));
	start_int = start;
	if (len > str_len)
		len = str_len;
	size = min(start_int + len, str_len) - start_int;
	substr = ft_calloc(size + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		substr[i] = s[i + start_int];
		i++;
	}
	return (substr);
}
