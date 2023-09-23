#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../libft.h"

char to_uppercase(unsigned int i, char c) {
	if (i) {}
	return toupper(c);
}

int main() {
	{
		char *s = "great captain usopp";

		char *expected = "GREAT CAPTAIN USOPP";
		char *received = ft_strmapi(s, to_uppercase);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strmapi(\"%s\", to_uppercase)\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = NULL;

		char *expected = NULL;
		char *received = ft_strmapi(s, to_uppercase);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strmapi(\"%s\", to_uppercase)\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = "great captain usopp";

		char *expected = NULL;
		char *received = ft_strmapi(s, NULL);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strmapi(\"%s\", NULL)\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_strmapi\n");
}
