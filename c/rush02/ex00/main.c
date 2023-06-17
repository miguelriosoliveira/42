/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:50:32 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/17 16:50:34 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int input_checker(char *str);

void	print_dict_error(void)
{
	write(1, "Dict Error\n", 11);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

char  *get_number_name(char *number, int fileDescriptor)
{
  char	buffer[1];
  // char  *number_name = "number_name";
  int   match_counter;
  int   number_len;

  match_counter = 0;
  number_len = ft_strlen(number);
  while (read(fileDescriptor, buffer, sizeof(buffer)) > 0)
	{
    if (number[match_counter] == buffer[0])
    {
      match_counter++;
      if (match_counter == number_len)
      {
        read(fileDescriptor, buffer, sizeof(buffer));
        if (buffer[0] < '0' || buffer[0] > '9')
          // return (number_name);
          return (number);
      }
    }
    else
      match_counter = 0;
	}
  // return (number_name);
  return (number);
}

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

void  function(int num, int count)
{
  if (num <= 9)
  {
    ft_putchar('-');
    ft_putnbr(num);
    if (count >= 100)
    {
      ft_putchar('-');
      ft_putnbr(count);
    }
  }
  else if (num < 100)
  {
    function(num / 10, count * 10);
    function(num % 10, count);
  }
  else
  {
    function(num / 10, count * 10);
    function(num % 10, count);
  }
}

int	main(int argc, char **argv)
{
	int		fileDescriptor;
	// char	buffer[1];
  int   number;
	char	*dict_name;

  // Validacion del input
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
	{
		number = input_checker(argv[1]);
		dict_name = "numbers.dict";
	}
	else
	{
		number = input_checker(argv[2]);
		dict_name = argv[1];
	}

	fileDescriptor = open("numbers.dict", O_RDONLY);
	if (fileDescriptor == -1)
	{
		print_dict_error();
		return (1);
	}


  function(number, 1);


	if (close(fileDescriptor) == -1)
	{
		print_dict_error();
		return (1);
	}
	return (0);
}
