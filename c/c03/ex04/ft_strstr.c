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
	int i;
	int j;
	int to_find_len;
	int	match_pos;

	to_find_len = ft_strlen(to_find);
	if (to_find_len == 0)
		return str;
	i = 0;
	while (str[i] != to_find[0])
		i++;
	match_pos = i;
	j = 0;
	while (str[i+j] && str[i+j] == to_find[j])
		j++;
	if (j == to_find_len)
		return (&str[match_pos]);
	return (NULL);
}