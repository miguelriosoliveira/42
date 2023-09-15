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
		"END",
	};
	while (strcmp(*strs, "END") != 0) {
		char *str = *strs;

		char *expected = strdup(str);
		char *received = ft_strdup(str);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strdup(\"%s\")\n", result, str);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}

		strs++;
	}
	printf("✅ ft_strdup\n");
}
