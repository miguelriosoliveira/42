#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	char **strs = (char *[]){
		"123abc",
		"abc123",
		"-123",
		"+123",
		"--123",
		"++123",
		"+-123",
		"-+123",
		"\t\v\f\r\n \f-06050",
		"\t\v\f\r\n \f",
		"\e123456789",
		NULL,
	};
	while (*strs) {
		char *str = *strs;

		int expected = atoi(str);
		int received = ft_atoi(str);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_atoi(\"%s\")\n", result, str);
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}

		strs++;
	}

	printf("✅ ft_atoi\n");
}
