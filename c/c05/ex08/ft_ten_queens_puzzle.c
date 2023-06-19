int	is_valid(int *queens_positions, int step)
{

}

int	solve(int *queens_positions, int step, int *solution_count)
{
	if (step > 10)
		return *solution_count;
	while (queens_positions[step] != 10 && *solution_count != 10)
	{
		queens_positions[step]++;
		if (is_valid(queens_positions, step)) {
			if (step != 10)
				*solution_count = solve(queens_positions, step + 1, solution_count);
			else
				*solution_count += 1;
		}
	}
	return *solution_count;
}

int	ft_ten_queens_puzzle(void)
{
	int	*queens_positions;
	int	solution_count;

	queens_positions = {-1};
	solution_count = 0;
	return (solve(queens_positions, 0, &solution_count));
}
