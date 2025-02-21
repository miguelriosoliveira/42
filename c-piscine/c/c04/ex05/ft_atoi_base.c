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

int	find_index(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base, int base_size)
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
		result = result * base_size + pos_in_base;
		i++;
		pos_in_base = find_index(str[i], base);
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
			|| find_index(c, forbidden_chars) >= 0
			|| find_index(c, &base[i + 1]) >= 0)
			return (0);
		i++;
	}
	return (ft_atoi(str, base, base_size));
}
