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

void	ft_putnbr(int nb)
{
	long	nb_long;
	char	nb_char;

	nb_long = nb;
	if (nb_long < 0)
	{
		write(1, "-", 1);
		nb_long = -nb_long;
	}
	if (nb_long >= 10)
	{
		ft_putnbr(nb_long / 10);
	}
	nb_char = nb_long % 10 + '0';
	write(1, &nb_char, 1);
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
	write(1, "\n", 1);
}

int	is_valid(int *solution, int step)
{
	int	i;
	int	is_in_row;
	int	row_distance;
	int	col_distance;
	int	is_in_diagonal;

	i = 0;
	while (i < step)
	{
		is_in_row = solution[i] == solution[step];
		row_distance = solution[i] - solution[step];
		if (row_distance < 0)
			row_distance = -row_distance;
		col_distance = i - step;
		if (col_distance < 0)
			col_distance = -col_distance;
		is_in_diagonal = row_distance == col_distance;
		if (is_in_row || is_in_diagonal)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *solution, int i, int *solution_count)
{
	int	step;

	if (i == SIZE)
	{
		if (is_valid(solution, SIZE - 1))
		{
			*solution_count += 1;
			print_solution(solution);
		}
		return ;
	}
	step = 0;
	while (step < SIZE)
	{
		solution[i] = step;
		if (is_valid(solution, i))
		{
			solve(solution, i + 1, solution_count);
		}
		step++;
	}
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
	solve(solution, 0, &solution_count);
	return (solution_count);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d solutions\n", ft_ten_queens_puzzle());
}
*/