#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	{
		size_t count = 3;
		size_t size = sizeof(char);

		void *expected = calloc(count, size);
		void *received = ft_calloc(count, size);

		int passed = memcmp(expected, received, count * size) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_calloc(%zu, %zu)\n", result, count, size);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		size_t count = 0;
		size_t size = sizeof(char);

		void *expected = calloc(count, size);
		void *received = ft_calloc(count, size);

		int passed = memcmp(expected, received, count * size) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_calloc(%zu, %zu)\n", result, count, size);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		size_t count = 128 * 1024 * 1024;
		size_t size = sizeof(int);

		void *expected = calloc(count, size);
		void *received = ft_calloc(count, size);

		int passed = memcmp(expected, received, count * size) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_calloc(%zu, %zu)\n", result, count, size);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		int size = 8539;
		void * d1 = ft_calloc(size, sizeof(int));
		void * d2 = calloc(size, sizeof(int));
		if (memcmp(d1, d2, size * sizeof(int)))
			return 1;
		free(d1);
		free(d2);
	}
	printf("✅ ft_calloc\n");
}
