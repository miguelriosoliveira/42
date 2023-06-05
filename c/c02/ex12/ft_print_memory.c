#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void  *ft_print_memory(void *addr, unsigned int size)
{
  char  *str;
  char	*hex_digits;
  unsigned int   i;
  unsigned int   j;

  if (size == 0)
    return "";
  hex_digits = "0123456789abcdef";
  str = (char*)addr;
  i = 0;
  while (i < size)
  {
    long address = (long)&str[i];
    while (address > 0) {
      char digit = address % 16;
      ft_putchar(hex_digits[digit / 16]);
      ft_putchar(hex_digits[digit % 16]);
      address /= 16;
    }
    ft_putchar(':');
    ft_putchar(' ');
    j = i;
    while (j < i + 15)
    {
      if (str[j])
      {
        ft_putchar(hex_digits[str[j] / 16]);
        ft_putchar(hex_digits[str[j] % 16]);
        ft_putchar(hex_digits[str[j+1] / 16]);
        ft_putchar(hex_digits[str[j+1] % 16]);
      }
      else
      {
        ft_putchar(' ');
        ft_putchar(' ');
        ft_putchar(' ');
        ft_putchar(' ');
      }
      ft_putchar(' ');
      j++;
    }
    j = i;
    while (j < i + 16 && str[j])
    {
      ft_putchar(str[j]);
      j++;
    }
    ft_putchar('\n');
    i += 16;
  }
  return addr;
}

#include <string.h>

int main() {
  char *addr = "Bonjour les aminches...c. est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. .";
  ft_print_memory(addr, strlen(addr));
  return 0;
}