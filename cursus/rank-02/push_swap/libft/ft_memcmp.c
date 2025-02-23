/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:11 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:11 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;
	const char		*str1;
	const char		*str2;

	if (n == 0)
		return (0);
	i = 0;
	str1 = s1;
	str2 = s2;
	c1 = str1[0];
	c2 = str2[0];
	while (i < n && c1 == c2)
	{
		c1 = str1[i];
		c2 = str2[i];
		i++;
	}
	return (c1 - c2);
}
