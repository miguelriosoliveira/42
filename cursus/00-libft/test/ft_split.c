#include <stdio.h>
#include <string.h>
#include "../libft.h"

void print_array(char **arr) {
	for (int i=0; i < (sizeof (foo) /sizeof (foo[0])); i++) {
		printf("\"%s\"\n", foo[i]);
	}
}

int compare_arrays(char **a, char **b, int size) {
  for(int i = 0; i <= size; i++) {
    if (a[i] != b[i])
		return 0;
  }
  return 1;
}

int main() {
	{
		char *s1 = "great captain usopp";
		char c = ' ';

		char **expected = {"great", "captain", "usopp", NULL};
		char **received = ft_split(s1, c);

		int passed = compare_arrays(expected, received);
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_split(\"%s\", '%c')\n", result, s1, c);
			printf("expected:\n");
			print_array(expected);
			printf("received:\n");
			print_array(received);
			return 1;
		}
	}

	printf("✅ ft_split\n");
}
