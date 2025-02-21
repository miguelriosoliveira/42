/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:49:44 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/29 16:50:05 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
int		find_index(char c, char *str);

int	is_valid_base(char *base)
{
	int		i;
	char	c;
	int		is_printable;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		c = base[i];
		is_printable = (c >= 32 && c <= 126);
		if (!is_printable
			|| find_index(c, "+- ") >= 0
			|| find_index(c, &base[i + 1]) >= 0)
			return (0);
		i++;
	}
	return (1);
}

int	atoi_base(char *str, char *base)
{
	int		i;
	long	result;
	int		sign;
	int		pos_in_base;

	i = 0;
	sign = 1;
	while (str[i] && !(str[i] > 32 && str[i] <= 126))
		i++;
	while (str[i] && find_index(str[i], "+-") >= 0)
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	pos_in_base = find_index(str[i], base);
	while (str[i] && pos_in_base >= 0)
	{
		result = result * ft_strlen(base) + pos_in_base;
		i++;
		pos_in_base = find_index(str[i], base);
	}
	return (sign * result);
}

int	get_nbr_len(int nbr, int base_len, int result_len)
{
	long	nbr_long;

	nbr_long = nbr;
	if (nbr_long < 0)
	{
		result_len++;
		nbr_long = -nbr_long;
	}
	if (nbr_long >= base_len)
		return (get_nbr_len(nbr_long / base_len, base_len, result_len + 1));
	return (result_len);
}

void	nbr_base(int nbr, char *base, char *buffer)
{
	long	nbr_long;
	int		base_len;
	char	c[2];

	c[1] = '\0';
	nbr_long = nbr;
	if (nbr_long < 0)
	{
		ft_strcat(buffer, "-");
		nbr_long = -nbr_long;
		c[0] = '-';
	}
	base_len = ft_strlen(base);
	if (nbr_long >= base_len)
		nbr_base(nbr_long / base_len, base, buffer);
	c[0] = base[nbr_long % base_len];
	ft_strcat(buffer, c);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_int;
	int		nbr_base_len;
	int		i;
	char	*nbr_in_base;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	nbr_int = atoi_base(nbr, base_from);
	nbr_base_len = get_nbr_len(nbr_int, ft_strlen(base_to), 1);
	nbr_in_base = malloc((nbr_base_len + 1) * sizeof(char));
	i = 0;
	while (i <= nbr_base_len)
	{
		nbr_in_base[i] = '\0';
		i++;
	}
	nbr_base(nbr_int, base_to, nbr_in_base);
	return (nbr_in_base);
}

/*
#include <stdio.h>
int main(void) {
	char *nbr;
	char *from;
	char *to;
	char *binary = "01";
	char *decimal = "0123456789";
	char *hexadecimal = "0123456789abcdef";

	char *decimal_numbers[] = {
		"-10", "-5", "-2", "-1",
		"0", "1", "2", "5", "10", "15", "16", "17",
		NULL
	};
	int i = 0;
	from = decimal;
	to = binary;
	while (decimal_numbers[i]) {
		nbr = decimal_numbers[i];
		printf("ft_convert_base(\"%s\", \"%s\", \"%s\")", nbr, from, to);
		printf(": \"%s\"", ft_convert_base(nbr, from, to));
		printf("\n");
		i++;
	}

	printf("\n-----------------------------------------------------------\n\n");

	i = 0;
	from = decimal;
	to = hexadecimal;
	while (decimal_numbers[i]) {
		nbr = decimal_numbers[i];
		printf("ft_convert_base(\"%s\", \"%s\", \"%s\")", nbr, from, to);
		printf(": \"%s\"", ft_convert_base(nbr, from, to));
		printf("\n");
		i++;
	}

	printf("\n-----------------------------------------------------------\n\n");

	char *binary_numbers[] = {
		"-1010", "-101", "-10", "-1",
		"0", "1", "10", "101", "1010",
		NULL
	};
	i = 0;
	from = binary;
	to = decimal;
	while (binary_numbers[i]) {
		nbr = binary_numbers[i];
		printf("ft_convert_base(\"%s\", \"%s\", \"%s\")", nbr, from, to);
		printf(": \"%s\"", ft_convert_base(nbr, from, to));
		printf("\n");
		i++;
	}

	return 0;
}
*/