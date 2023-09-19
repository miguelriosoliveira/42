/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:16:33 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/05 11:16:36 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z')
			&& !(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int main(void) {
	char* alpha_word = "yes";
	char *result1 = ft_str_is_alpha(alpha_word);
	printf("\"%s\" is alpha? %d\n", alpha_word, result1);
	
	char* not_alpha_word = "yes1";
	char *result2 = ft_str_is_alpha(not_alpha_word);
	printf("\"%s\" is alpha? %d\n", not_alpha_word, result2);
	
	char* empty_word = "";
	char *result3 = ft_str_is_alpha(empty_word);
	printf("\"%s\" is alpha? %d\n", empty_word, result3);

	char* uppercase_alpha_word = "POTATO";
	char *result3 = ft_str_is_alpha(uppercase_alpha_word);
	printf("\"%s\" is alpha? %d\n", uppercase_alpha_word, result3);
	
	char* uppercase_not_alpha_word = "P07470";
	char *result3 = ft_str_is_alpha(uppercase_not_alpha_word);
	printf("\"%s\" is alpha? %d\n", uppercase_not_alpha_word, result3);
	
	return 0;
}
*/