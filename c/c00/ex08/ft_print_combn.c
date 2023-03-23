#include <unistd.h>

int MAX_N = 9;

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_print_combn(int n, int start) {
	int a = '0' + start;
	int end = '9' - n + 1;
	while (a <= end) {
		ft_print_combn(n-1, start+1);
		a++;
	}
}

int main(void) {
	ft_print_combn(2);
	return 0;
}

