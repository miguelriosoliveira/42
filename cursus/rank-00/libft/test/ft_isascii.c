#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main() {
	for (int c = 0; c < 130; c++) {
		int expected = isascii(c);
		int received = ft_isascii(c);
		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("[%d] ft_isascii('%c'): %d | %s\n", c, c, received, result);
			return 1;
		}
	}
	printf("✅ ft_isascii\n");
}
