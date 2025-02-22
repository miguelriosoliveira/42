#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main() {
	for (int c = 0; c < 130; c++) {
		int expected = isprint(c);
		int received = ft_isprint(c);
		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("[%d] ft_isprint('%c'): %d | %s\n", c, c, received, result);
			return 1;
		}
	}
	printf("✅ ft_isprint\n");
}
