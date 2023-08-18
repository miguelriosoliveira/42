/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:28:05 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/01 15:28:38 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_error(char c)
{
	write(2, &c, 1);
}

/*
int main(void) {
  ft_putchar('h');
  ft_putchar('o');
  ft_putchar('l');
  ft_putchar('a');
  ft_putchar('!');
  return 0;
}
*/
