#include <unistd.h>

void ft_print_reverse_alphabet(void) {
  for (int i = 'z'; i >= 'a'; i--) {
    write(1, &i, 1);
  }
}