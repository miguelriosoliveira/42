#include <unistd.h>

void ft_putchar(char c) {
  write(1, &c, 1);
}

int main(void) {
  ft_putchar('h');
  ft_putchar('o');
  ft_putchar('l');
  ft_putchar('a');
  ft_putchar('!');
  return 0;
}
