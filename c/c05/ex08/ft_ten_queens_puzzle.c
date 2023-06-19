#include <unistd.h>

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

void  print_solution(int *queens_positions)
{
  int i;

  i = 0;
  while (i < 10)
  {
    ft_putnbr(queens_positions[i]);
    i++;
  }
  ft_putchar('\n');
}

int absolute(int a, int b)
{
  int result;

  result = a - b;
  if (result < 0)
    return (-result);
  return (result);
}

int	is_valid(int *queens_positions, int step)
{
  int i;
  int is_same_pos;
  int is_in_the_way;

  i = 0;
  while (i < step)
  {
    is_same_pos = (queens_positions[i] == queens_positions[step]);
    is_in_the_way = (absolute(queens_positions[i], queens_positions[step]) == absolute(i, step));
    if (is_same_pos || is_in_the_way)
      return (0);
    i++;
  }
  return (1);
}

int	solve(int *queens_positions, int step, int *solution_count)
{
	if (step > 10)
		return *solution_count;
	while (queens_positions[step] != 10 && *solution_count != 10)
	{
		queens_positions[step]++;
    print_solution(queens_positions);
		if (is_valid(queens_positions, step)) {
      ft_putchar('v');
      ft_putchar('\n');
			if (step != 10)
				*solution_count = solve(queens_positions, step + 1, solution_count);
			else
      {
				*solution_count += 1;
        print_solution(queens_positions);
      }
		}
	}
	return *solution_count;
}

int	ft_ten_queens_puzzle(void)
{
	int	queens_positions[10];
	int	solution_count;
  int i;


  i = 0;
  while (i < 10)
  {
    queens_positions[i] = -1;
    i++;
  }
	solution_count = 0;
	return (solve(queens_positions, 0, &solution_count));
}

#include <stdio.h>
int	main(void)
{
	printf("\n%d solutions\n", ft_ten_queens_puzzle());
}