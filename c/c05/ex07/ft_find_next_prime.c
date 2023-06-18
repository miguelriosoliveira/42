int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int ft_find_next_prime(int nb)
{
  while (!ft_is_prime(nb))
    nb++;
  return (nb);
}

/*
#include <stdio.h>
int main() {
  int nb = 0;
  int result = 0;
  while (nb < 100) {
    result = ft_is_prime(nb);
    if (result)
      printf("%3d is prime, the next prime is %d\n", nb, ft_find_next_prime(nb+1));
    nb++;
  }
	nb = 999983; // largest prime number under 1000000
  printf("the next prime after %3d is %d\n", nb, ft_find_next_prime(nb+1));
}
*/