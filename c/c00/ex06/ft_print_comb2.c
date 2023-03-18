#include <unistd.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_print_comb2(void) {
	int a = 0;
	while (a < 99) {
		int b = a + 1;
		while (b < 100) {
			int a_integer_part = a / 10;
			int a_remainder = a % 10;
			int b_integer_part = b / 10;
			int b_remainder = b % 10;
			ft_putchar('0' + a_integer_part);
			ft_putchar('0' + a_remainder);
			ft_putchar(' ');
			ft_putchar('0' + b_integer_part);
			ft_putchar('0' + b_remainder);
			if (a != 98) {
				ft_putchar(',');
				ft_putchar(' ');
			}
			b++;
		}
		a++;
	}
}

int main(void) {
	ft_print_comb2();
	return 0;
}

