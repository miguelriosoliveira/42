#include <unistd.h>

void ft_is_negative(int n) {
  char result = n < 0 ? 'N' : 'P';
  write(1, result, 1);
}