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
		char *b1 = strdup(str);
		char *b2 = strdup(str);
		int c = '*'; // 42
		size_t len = 0.3 * str_len;

		char *expected = memset(b1, c, len);
		char *received = ft_memset(b2, c, len);

		int passed = memcmp(expected, received, str_len) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("ft_memset(\"%s\"): \"%s\" | %s\n", str, received, result);
			return 1;
		}

		strs++;
	}
	printf("✅ ft_memset\n");
}
