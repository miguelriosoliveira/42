#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	char **strs = (char *[]){
		"great captain usopp",
		"king of pirates",
		"1234567",
		NULL,
	};
	while (*strs) {
		char *b = *strs;
		int c = 42;
		size_t len = 4;
		char *expected = memset(b, c, len);
		char *received = ft_memset(b, c, len);
		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("ft_memset(\"%s\"): \"%s\" | %s\n", b, received, result);
			return 1;
		}
		strs++;
	}
	printf("✅ ft_memset\n");
}
