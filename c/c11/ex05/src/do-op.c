/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:22:41 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/06 18:22:41 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

t_operation	get_operation(char *op)
{
	char		op_symbols[5];
	t_operation	op_functions[5];
	int			index;

	if (ft_strlen(op) != 1)
		return (0);
	op_symbols[0] = '+';
	op_functions[0] = &sum;
	op_symbols[1] = '-';
	op_functions[1] = &subtract;
	op_symbols[2] = '*';
	op_functions[2] = &multiply;
	op_symbols[3] = '/';
	op_functions[3] = &divide;
	op_symbols[4] = '%';
	op_functions[4] = &modulo;
	index = find_index(op[0], op_symbols);
	if (index < 0)
		return (0);
	return (op_functions[index]);
}

void	doop(char *value1, char *op, char *value2)
{
	int			v1;
	int			v2;
	t_operation	operation;

	v1 = ft_atoi(value1);
	v2 = ft_atoi(value2);
	if (v2 == 0)
	{
		if (ft_strcmp(op, "/") == 0)
		{
			ft_putstr("Stop : division by zero\n");
			return ;
		}
		if (ft_strcmp(op, "%") == 0)
		{
			ft_putstr("Stop : modulo by zero\n");
			return ;
		}
	}
	operation = get_operation(op);
	if (!operation)
		ft_putchar('0');
	else
		ft_putnbr(operation(v1, v2));
	ft_putchar('\n');
}
