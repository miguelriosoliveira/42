/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:12 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:12 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped;
	int		size;
	int		i;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	mapped = ft_calloc(size + 1, sizeof(char));
	if (!mapped)
		return (NULL);
	i = 0;
	while (i < size)
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	return (mapped);
}
