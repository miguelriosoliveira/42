/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:37:34 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/08 18:37:36 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (str[i] != to_find[i])
		i++;
	while (i < src_len - 1)
	{
		
		i++;
	}
}