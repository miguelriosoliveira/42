#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	char **strs = (char *[]){
		"great captain usopp",
		"king of pirates",
		(char *)malloc(5 * sizeof(char)),
		"1234567",
		"",
		NULL,
	};
	while (*strs) {
		char *str = *strs;
		int str_len = strlen(str);
		char *s1 = strdup(str);
		char *s2 = strdup(str);
		size_t len = 0.3 * str_len;

		bzero(s1, len);
		ft_bzero(s2, len);
		char *expected = s1;
		char *received = s2;

		int passed = memcmp(expected, received, str_len) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("ft_bzero(\"%s\"): \"%s\" | %s\n", str, received, result);
			return 1;
		}

		strs++;
	}
	printf("✅ ft_bzero\n");
}
