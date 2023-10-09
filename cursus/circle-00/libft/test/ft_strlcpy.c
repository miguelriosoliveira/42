#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {

	{
		char *str = "great captain usopp";
		char dst1[] = "AAAAAAAAAA";
		char dst2[] = "AAAAAAAAAA";
		size_t len = 5;

		strlcpy(dst1, str, len);
		ft_strlcpy(dst2, str, len);

		char *expected = dst1;
		char *received = dst2;

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strlcpy(\"%s\")\n", result, str);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	{
		char *str = "king of pirates";
		char dst1[] = "BBBBBBBBBB";
		char dst2[] = "BBBBBBBBBB";
		size_t len = 11;

		strlcpy(dst1, str, len);
		ft_strlcpy(dst2, str, len);

		char *expected = dst1;
		char *received = dst2;

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strlcpy(\"%s\")\n", result, str);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_strlcpy\n");
}
