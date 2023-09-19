/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:22:33 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/05 12:22:35 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	offset;
	int	i;

	offset = 'a' - 'A';
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += offset;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		offset;
	int		i;
	char	prev_c;
	char	curr_c;

	ft_strlowcase(str);
	offset = 'a' - 'A';
	i = 0;
	while (str[i])
	{
		prev_c = str[i - 1];
		curr_c = str[i];
		if (!(prev_c >= 'A' && prev_c <= 'Z')
			&& !(prev_c >= 'a' && prev_c <= 'z')
			&& !(prev_c >= '0' && prev_c <= '9')
			&& (curr_c >= 'a' && curr_c <= 'z'))
			str[i] -= offset;
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int main(void) {
	char w1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	//char *res1 = ft_strcapitalize(w1);
	printf("\"%s\"", w1);
	printf("\n");
	printf("\"%s\"", ft_strcapitalize(w1));
	
	printf("\n");
	return 0;
}
*/