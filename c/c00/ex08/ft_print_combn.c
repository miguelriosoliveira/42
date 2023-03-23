#include <unistd.h>

int MAX_N = 9;

void ft_putchar(char c) {
	write(1, &c, 1);
}

void print_combn(int n, int start, char* buffer) {
	if (n == 0) {
		write(1, buffer, MAX_N);
	}

	int i = start;
	while (i <= MAX_N) {
		char new_buffer[MAX_N] = buffer + '0' + i;
		print_combn(n-1, i+1, new_buffer);
		i++;
	}
}

void ft_print_combn(int n) {
	int start = 0;
	char* buffer = "";
	print_combn(n, start, buffer);
}

int main(void) {
	ft_print_combn(2);
	return 0;
}

