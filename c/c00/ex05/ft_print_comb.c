#include <unistd.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_print_comb(void) {
  int i = 0;
  while (i <= 7) {
    int j = i+1;
    while (j <= 8) {
      int k = j+1;
      while (k <= 9) {
        ft_putchar('0' + i);
        ft_putchar('0' + j);
        ft_putchar('0' + k);
        if (i < 7) {
        	ft_putchar(',');
        	ft_putchar(' ');
        }
        k++;
      }
      j++;
    }
    i++;
  }
}

int main(void) {
  ft_print_comb();
  return 0;
}
