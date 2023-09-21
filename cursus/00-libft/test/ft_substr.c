#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	{
		char *s = "great captain usopp";
		int start = 6;
		int len = 13;

		char *expected = "captain usopp";
		char *received = ft_substr(s, start, len);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_substr(\"%s\", %d, %d)\n", result, s, start, len);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = "great captain usopp";
		int start = 14;
		int len = 15;

		char *expected = "usopp";
		char *received = ft_substr(s, start, len);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_substr(\"%s\", %d, %d)\n", result, s, start, len);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = "great captain usopp";
		int start = strlen(s) + 1;
		int len = 15;

		char *expected = "";
		char *received = ft_substr(s, start, len);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_substr(\"%s\", %d, %d)\n", result, s, start, len);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = "great captain usopp";
		int start = 100;
		int len = 15;

		char *expected = "";
		char *received = ft_substr(s, start, len);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_substr(\"%s\", %d, %d)\n", result, s, start, len);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_substr\n");
}
