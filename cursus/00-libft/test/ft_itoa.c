#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	{
		int n = 123;

		char *expected = "123";
		char *received = ft_itoa(n);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_itoa(%d)\n", result, n);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		int n = -123;

		char *expected = "-123";
		char *received = ft_itoa(n);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_itoa(%d)\n", result, n);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_itoa\n");
}
