#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	char **strs = (char *[]){
		"great captain usopp",
		"king of pirates",
		"",
		NULL,
	};
	while (*strs) {
		char *s = *strs;
		int expected = strlen(s);
		int received = ft_strlen(s);
		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("ft_strlen(\"%s\"): %d | %s\n", s, received, result);
			return 1;
		}
		strs++;
	}
	printf("✅ ft_strlen\n");
}
