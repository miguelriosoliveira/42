#include <unistd.h>

void ft_print_comb(void) {
  int i = '0';
  while (i <= '7') {
    int j = i+1;
    while (j <= '8') {
      int k = j+1;
      while (k <= '9') {
        write(1, &i, 1);
        write(1, &j, 1);
        write(1, &k, 1);
        if (i < '7') {
          write(1, ", ", 2);
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