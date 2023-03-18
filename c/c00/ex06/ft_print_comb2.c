#include <unistd.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_print_comb2(void) {
	int a = 0;
	while (a < 99) {
		int b = a + 1;
		while (b < 100) {
			ft_putchar('0' + a / 10);
			ft_putchar('0' + a % 10);
			ft_putchar(' ');
			ft_putchar('0' + b / 10);
			ft_putchar('0' + b % 10);
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

