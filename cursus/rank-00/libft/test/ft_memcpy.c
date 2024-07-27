#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	char **strs = (char *[]){
		"great captain usopp",
		"king of pirates",
		(char *)malloc(5 * sizeof(char)),
		NULL,
		"1234567",
		"",
		"END",
	};
	while (*strs == NULL || strcmp(*strs, "END") != 0) {
		char *str = *strs;

		char *dst = "0123456789";
		char *dst1 = strdup(dst);
		char *dst2 = strdup(dst);
		char *src = str;
		size_t n = 0.3 * (src ? strlen(src) : 0);

		memcpy(dst1, src, n);
		ft_memcpy(dst2, src, n);
		char *expected = dst1;
		char *received = dst2;

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_memcpy(\"%s\")\n", result, src);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}

		strs++;
	}
	printf("✅ ft_memcpy\n");
}
