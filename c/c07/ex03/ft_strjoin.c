/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:49:07 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/22 15:49:09 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

int	calculate_len(int size, char **strs, char *sep)
{
	int	i;
	int	result_len;

	i = 0;
	result_len = (size - 1) * ft_strlen(sep);
	while (i < size)
	{
		result_len += ft_strlen(strs[i]);
		i++;
	}
	return (result_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		result_len;
	char	*result;

	if (size == 0)
	{
		result = malloc(sizeof(char));
		result[0] = '\0';
		return (result);
	}
	result_len = calculate_len(size, strs, sep);
	result = malloc((result_len + 1) * sizeof(char));
	i = 0;
	while (i < size - 1)
	{
		result = ft_strcat(result, strs[i]);
		result = ft_strcat(result, sep);
		i++;
	}
	result = ft_strcat(result, strs[i]);
	result[result_len] = '\0';
	return (result);
}

/*
#include <stdio.h>
int main(void) {
	int size;
	char **strs;
	char *sep;

	size = 0;
	strs = NULL;
	sep = ",";
	printf("\"%s\"",  ft_strjoin(size, strs, sep));
	printf("\n");
	printf("\n");

	size = 1;
	strs = (char*[]){ "Hello" };
	sep = ",";
	printf("\"%s\"",  ft_strjoin(size, strs, sep));
	printf("\n");
	printf("\n");

	size = 3;
	strs = (char*[]){ "Hello", "world", "!" };
	sep = ", ";
	printf("\"%s\"",  ft_strjoin(size, strs, sep));
	printf("\n");
	printf("\n");

	size = 4;
	strs = (char*[]){ "", "Hello", "", "world" };
	sep = "-";
	printf("\"%s\"",  ft_strjoin(size, strs, sep));
	printf("\n");
	printf("\n");

	size = 2;
	strs = (char*[]){ "Hello", "world" };
	sep = "";
	printf("\"%s\"",  ft_strjoin(size, strs, sep));
	printf("\n");
	return (0);
}
*/