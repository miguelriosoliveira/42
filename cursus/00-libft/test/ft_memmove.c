#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	{
		char *src = "great captain usopp";
		char *dst = "0123456789";
		char *dst1 = strdup(dst);
		char *dst2 = strdup(dst);
		size_t len = 5;

		char *expected = memmove(dst1, src, len);
		char *received = ft_memmove(dst2, src, len);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_memmove(\"%s\", \"%s\", %zu)\n", result, dst, src, len);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *src = "king of pirates";
		char *dst = src + 5;
		char *dst1 = strdup(dst);
		char *dst2 = strdup(dst);
		size_t len = 4;

		char *expected = memmove(dst1, src, len);
		char *received = ft_memmove(dst2, src, len);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_memmove(\"%s\", \"%s\", %zu)\n", result, dst, src, len);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_memmove\n");
}
