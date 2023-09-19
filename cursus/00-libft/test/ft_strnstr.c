#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	{
		char *haystack = "great captain usopp";
		char *needle = "apt";
		int len = 16;

		char *expected = strnstr(haystack, needle, len);
		char *received = ft_strnstr(haystack, needle, len);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strnstr(\"%s\")\n", result, haystack);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *haystack = "great captain usopp";
		char *needle = "us";
		int len = 5;

		char *expected = strnstr(haystack, needle, len);
		char *received = ft_strnstr(haystack, needle, len);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strnstr(\"%s\")\n", result, haystack);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *haystack = "great captain usopp";
		char *needle = "";
		int len = 50;

		char *expected = strnstr(haystack, needle, len);
		char *received = ft_strnstr(haystack, needle, len);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strnstr(\"%s\")\n", result, haystack);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *haystack = "MZIRIBMZIRIBMZE123";
		char *needle = "MZIRIBMZE";
		int len = strlen(needle);

		char *expected = strnstr(haystack, needle, len);
		char *received = ft_strnstr(haystack, needle, len);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strnstr(\"%s\")\n", result, haystack);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_strnstr\n");
}
