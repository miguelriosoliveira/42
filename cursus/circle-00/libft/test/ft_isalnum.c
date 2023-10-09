#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main() {
	for (int c = 0; c < 130; c++) {
		int expected = isalnum(c);
		int received = ft_isalnum(c);
		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("[%d] ft_isalnum('%c'): %d | %s\n", c, c, received, result);
			return 1;
		}
	}
	printf("✅ ft_isalnum\n");
}
