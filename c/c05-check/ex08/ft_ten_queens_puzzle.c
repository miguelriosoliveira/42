/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:49:13 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/19 18:49:15 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 10

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nb_long;

	nb_long = nb;
	if (nb_long < 0)
	{
		ft_putchar('-');
		nb_long = -nb_long;
	}
	if (nb_long >= 10)
	{
		ft_putnbr(nb_long / 10);
	}
	ft_putchar('0' + nb_long % 10);
}

void	print_solution(int *solution)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		ft_putnbr(solution[i]);
		i++;
	}
	ft_putchar('\n');
}

int	is_valid(int *solution, int i)
{
	int	j;
	int	is_same_pos;
	int	diff_pos;
	int	diff_index;
	int	is_in_the_way;

	j = i - 1;
  q_row = solution[i];
	while (j > 0)
	{
		if (solution[j] == q_row)
			return (0);
		j--;
	}
	j = i - 1;
  q_row = solution[i];
	while (j > 0)
	{
		if (solution[j] == q_row)
			return (0);
		j--;
	}
	return (1);
}

int	solve(int *solution, int i, int *solution_count)
{
  int step;

	if (i == SIZE)
		return (*solution_count);
  step = 0;
	while (step < SIZE)
	{
    solution[i] = step;
    if (is_valid(solution, step))
			*solution_count += solve(solution, i + 1, solution_count);
    step++;
	}
	return (*solution_count);
}

int	ft_ten_queens_puzzle(void)
{
	int	solution[SIZE];
	int	solution_count;
	int	i;

	i = 0;
	while (i < SIZE)
	{
		solution[i] = -1;
		i++;
	}
	solution_count = 0;
	return (solve(solution, 0, &solution_count));
}


#include <stdio.h>
int	main(void)
{
	printf("\n%d solutions\n", ft_ten_queens_puzzle());
}
