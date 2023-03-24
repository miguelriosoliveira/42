#include <unistd.h>

void ft_putchar(char c) {
  write(1, &c, 1);
}

void ft_is_negative(int n) {
  char result = n < 0 ? 'N' : 'P';
  ft_putchar(result);
}

int main(void) {
  ft_is_negative(-42);
  ft_putchar('\n');
  ft_is_negative(42);
  ft_putchar('\n');
  return 0;
}
