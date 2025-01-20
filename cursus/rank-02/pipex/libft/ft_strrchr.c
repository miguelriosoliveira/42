/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:12 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:12 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		str_len;
	char	chr;

	str = (char *)s;
	str_len = ft_strlen(str);
	chr = c;
	if (chr == '\0')
		return (&str[str_len]);
	i = str_len;
	while (i > 0)
	{
		i--;
		if (str[i] == chr)
			return (&str[i]);
	}
	return (NULL);
}
