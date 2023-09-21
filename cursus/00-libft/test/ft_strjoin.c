#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	{
		char *s1 = "great";
		char *s2 = " captain usopp";

		char *expected = "great captain usopp";
		char *received = ft_strjoin(s1, s2);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strjoin(\"%s\", \"%s\")\n", result, s1, s2);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_strjoin\n");
}
