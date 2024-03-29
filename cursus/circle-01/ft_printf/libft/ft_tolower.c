/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:12 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:12 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_tolower(int c)
{
	int	offset;

	offset = 'a' - 'A';
	if (is_upper(c))
		c += offset;
	return (c);
}
