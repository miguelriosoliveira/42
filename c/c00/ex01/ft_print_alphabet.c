#include <unistd.h>

void ft_print_alphabet(void) {
  for (int i = 'a'; i <= 'z'; i++) {
    write(1, &i, 1);
  }
}