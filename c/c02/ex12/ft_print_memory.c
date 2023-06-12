#include <unistd.h>

void	print_address(void *ptr)
{
	unsigned long	address;
	char			*hex;
	char			buffer[16];
	int				i;

	address = (unsigned long)ptr;
	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buffer[i] = hex[address % 16];
		address /= 16;
		i--;
	}
	write(1, buffer + i + 1, 15 - i);
	write(1, ":", 1);
}

void	print_hex_line(unsigned int size, unsigned int i, unsigned char *ptr)
{
	char			*hex;
	unsigned int	j;
	unsigned char	byte;
	char			hex_left;
	char			hex_right;

	hex = "0123456789abcdef";
	j = 0;
	while (j < 16 && i + j < size)
	{
		if (j % 2 == 0)
			write(1, " ", 1);
		byte = ptr[i + j];
		hex_left = hex[byte / 16];
		hex_right = hex[byte % 16];
		write(1, &hex_left, 1);
		write(1, &hex_right, 1);
		j++;
	}
	while (j < 16)
	{
		if (j % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		j++;
	}
	write(1, " ", 1);
}

void	print_chars(unsigned int size, unsigned int i, unsigned char *ptr)
{
	int				j;
	unsigned char	byte;

	j = 0;
	while (j < 16 && i + j < size)
	{
		byte = ptr[i + j];
		if (byte >= 32 && byte <= 126)
			write(1, &byte, 1);
		else
			write(1, ".", 1);
		j++;
	}
}

void *ft_print_memory(void *addr, unsigned int size) {
	unsigned char	*ptr;
	unsigned int	i;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size) {
		print_address(ptr+i);
		print_hex_line(size, i, ptr);
		print_chars(size, i, ptr);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
