#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {

	{
		char *src = " captain usopp";
		char dst1[20] = "great";
		char dst2[20] = "great";
		size_t len = 20;

		strlcat(dst1, src, len);
		ft_strlcat(dst2, src, len);

		char *expected = dst1;
		char *received = dst2;

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strlcat(\"%s\")\n", result, src);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	{
		char *src = "pirates";
		char dst1[16] = "king of ";
		char dst2[16] = "king of ";
		size_t len = 10;

		strlcat(dst1, src, len);
		ft_strlcat(dst2, src, len);

		char *expected = dst1;
		char *received = dst2;

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strlcat(\"%s\")\n", result, src);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_strlcat\n");
}
