/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:39:50 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/14 12:39:51 by mrios-es         ###   ########.fr       */
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

int	includes(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str, char *base)
{
	int		i;
	int		j;
	long	result;
	int		sign;
	int		base_size;

	i = 0;
	sign = 1;
	while (!is_numeric(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	base_size = ft_strlen(base);
	while (str[i])
	{
		j = 0;
		while (j < base_size)
		{
			if (str[i] == base[j])
			{
				result *= base_size;
				result += j;
				break ;
			}
			j++;
		}
		if (j == base_size)
			return (0);
		i++;
	}
	return (sign * result);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		base_size;
	int		is_printable;
	char	c;
	char	*forbidden_chars;

	forbidden_chars = "+- ";
	base_size = ft_strlen(base);
	if (base_size < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		c = base[i];
		is_printable = (c >= 32 && c <= 126);
		if (!is_printable
			|| includes(c, forbidden_chars)
			|| includes(c, &base[i + 1]))
			return (0);
		i++;
	}
	return (ft_atoi(str, base));
}
