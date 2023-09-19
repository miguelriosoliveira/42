#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	{
		char *s = "great captain usopp";
		char c = 'u';

		char *expected = strchr(s, c);
		char *received = ft_strchr(s, c);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = "great captain usopp";
		char c = 'z';

		char *expected = strchr(s, c);
		char *received = ft_strchr(s, c);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = "great captain usopp";
		char c = '\0';

		char *expected = strchr(s, c);
		char *received = ft_strchr(s, c);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_strchr\n");
}
