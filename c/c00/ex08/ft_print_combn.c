#include <unistd.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

void print_buffer(char* buffer) {
	int i = 0;
	while (buffer[i] != '\0') {
		ft_putchar(buffer[i]);
		i++;
	}
}

void print_combn(int pos, int n, int start, char* buffer) {
	if (pos == 0) {
    print_buffer(buffer);
    if (buffer[0] < '9'-n+1) {
      ft_putchar(',');
      ft_putchar(' ');
    }
		return;
	}

	int i = start;
	while (i <= 10-pos) {
		buffer[n - pos] = '0'+i;
		buffer[n - pos + 1] = '\0';
		print_combn(pos-1, n, i+1, buffer);
		i++;
	}
}

void ft_print_combn(int n) {
	char buffer[10];
	print_combn(n, n, 0, buffer);
}

int main(void) {
  int i = 1;
  while (i <= 9) {
    ft_putchar('n');
    ft_putchar('=');
    ft_putchar('0'+i);
    ft_putchar('\n');
    ft_print_combn(i);
    ft_putchar('\n');
    ft_putchar('\n');
    i++;
  }

	return 0;
}
