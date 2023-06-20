#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
	int	x;
	int	y;
	int	side;
} Solution;

typedef struct {
	int		height;
	int		width;
	char	empty_char;
	char	block_char;
	char	full_char;
	int		**map;
} Map;

Map	*read_map_from_file(char *file_name)
{
	int		file_descriptor;
	int		line_len;
	int		i;
	char	line_buffer[9999];
	char	buffer[0];
	Map		*map;

	file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor == -1)
	{
		write(1, "Error\n", 1);
		exit(1);
	}
	map = malloc(sizeof(Map));
	read(file_descriptor, line_buffer, 5);
	map->height = line_buffer[0] - '0';
	map->empty_char = line_buffer[1];
	map->block_char = line_buffer[2];
	map->full_char = line_buffer[3];
	map->map = malloc(map->height * sizeof(int*));
	i = 0;
	while (i < map->height)
	{
		line_len = 0;
		while (read(file_descriptor, buffer, 1) > 0 && buffer[0] != '\n')
		{
			line_buffer[line_len] = buffer[0];
			line_len++;
		}
		map->width = line_len;
		map->map[i] = malloc(map->width * sizeof(int));
		while (line_len > 0)
		{
			line_len--;
			map->map[i][line_len] = 0;
			if (line_buffer[line_len] == map->block_char)
				map->map[i][line_len] = 1;
		}
		i++;
	}
	close(file_descriptor);
	return (map);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// void	print_map(Map *map, Solution *solution)
void	print_map(Map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 0)
				ft_putchar(map->empty_char);
			else
				ft_putchar(map->block_char);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

Solution	*solve(Map *map,  Solution *solution)
{
	int	delta_h;
	int	delta_w;

	if (solution->x == map->width && solution->y == map->height)
		return (solution);
	delta_h = solution->y - map->height;
	delta_w = solution->x - map->width;
	while (solution->side < min(delta_h, delta_w))
	{

	}
}

// int	main(void)
int	main(int argc, char **argv)
{
	char			*file_name = "example_file";
	Map				*map;
	Solution	*solution;

	map = read_map_from_file(file_name);
	solution = solve_map(map, solution);
	// print_map(map, solution);
	print_map(map);
	// free_map(map);
	// free_solution(solution);
	return (0);
}
