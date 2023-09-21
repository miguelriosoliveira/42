#include <stdio.h>
#include <string.h>
#include "../libft.h"

void print_array(char **arr) {
	for (int i = 0; arr[i]; i++) {
		printf("\"%s\"\n", arr[i]);
	}
}

int compare_arrays(char **a, char **b) {
  for(int i = 0; a[i]; i++) {
    if (strcmp(a[i], b[i]) != 0) {
		printf("a[%d]: \"%s\"\n", i, a[i]);
		printf("b[%d]: \"%s\"\n", i, b[i]);
		return 0;
	}
  }
  return 1;
}

int main() {
	{
		char *s1 = "great captain usopp";
		char c = ' ';

		char **expected = (char *[]){"great", "captain", "usopp", NULL};
		char **received = ft_split(s1, c);

		int passed = compare_arrays(expected, received);
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_split(\"%s\", '%c')\n", result, s1, c);
			printf(">>>>> expected <<<<<\n\n");
			print_array(expected);
			printf("\n");
			printf(">>>>> received <<<<<\n\n");
			print_array(received);
			printf("\n");
			return 1;
		}
	}
	{
		char *s1 = "      split       this for   me  !       ";
		char c = ' ';

		char **expected = (char *[]){"split", "this", "for", "me", "!", NULL};
		char **received = ft_split(s1, c);

		int passed = compare_arrays(expected, received);
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_split(\"%s\", '%c')\n", result, s1, c);
			printf(">>>>> expected <<<<<\n\n");
			print_array(expected);
			printf("\n");
			printf(">>>>> received <<<<<\n\n");
			print_array(received);
			printf("\n");
			return 1;
		}
	}

	printf("✅ ft_split\n");
}
