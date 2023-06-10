/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:43:56 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/10 13:44:00 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define SIDE 4

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	print_map(int **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIDE)
	{
		ft_putchar(map[i][1] + '0');
		j = 1;
		while (j < SIDE)
		{
			ft_putchar(' ');
			ft_putchar(map[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_map_with_hints(int **map, char *hints)
{
	int	i;
	int	j;

	ft_putchar(' ');
	i = 0;
  while (i < SIDE)
  {
    ft_putchar(' ');
	  ft_putchar(hints[i]);
    i++;
  }
	ft_putchar('\n');
	i = 0;
	while (i < SIDE)
	{
		ft_putchar(hints[SIDE * 2 + i]);
    ft_putchar(' ');
		ft_putchar(map[i][1] + '0');
		j = 1;
		while (j < SIDE)
		{
			ft_putchar(' ');
			ft_putchar(map[i][j] + '0');
			j++;
		}
		ft_putchar(' ');
		ft_putchar(hints[SIDE * 3 + i]);
		ft_putchar('\n');
		i++;
	}
  ft_putchar(' ');
	i = 0;
  while (i < SIDE)
  {
    ft_putchar(' ');
	  ft_putchar(hints[SIDE + i]);
    i++;
  }
	ft_putchar('\n');
}

void parse_hints(char *raw_hints)
{
  int i;
  int j;

  i = 0;
  while (raw_hints[i])
  {
    if (raw_hints[i] == ' ')
    {
      j = i;
      while (raw_hints[j])
      {
        raw_hints[j] = raw_hints[j + 1];
        j++;
      }
    }
    i++;
  }
}

int	**create_map(void)
{
	int	i;
	int	j;
	int	**map;

	i = 0;
	map = malloc(SIDE * sizeof(int *));
	while (i < SIDE)
	{
		map[i] = malloc(SIDE * sizeof(int));
		i++;
	}
	while (i < SIDE)
	{
		j = 0;
		while (j < SIDE)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

void	free_map(int **map)
{
	int	i;

	i = 0;
	while (i < SIDE)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// void	solve_puzzle(int **map, char *hints)
// {

// }

#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*hints;
	int		**map;

	if (argc != 2)
	{
		print_error();
		return (0);
	}
	hints = argv[1];
	if (ft_strlen(hints) != SIDE * SIDE * 2 - 1)
	{
		print_error();
		return (0);
	}
  parse_hints(hints);
	map = create_map();
	// solve_puzzle(map, hints);
	// print_map(map);
	print_map_with_hints(map, hints);
	free_map(map);
	return (0);
}
