#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../libft.h"

void to_uppercase(unsigned int i, char *c) {
	if (i) {}
	*c = toupper(*c);
}

int main() {
	{
		char s[] = "great captain usopp";

		ft_striteri(s, to_uppercase);
		char *expected = "GREAT CAPTAIN USOPP";
		char *received = s;

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_striteri(\"%s\", to_uppercase)\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = NULL;

		ft_striteri(s, to_uppercase);
		char *expected = NULL;
		char *received = s;

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_striteri(\"%s\", to_uppercase)\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char s[] = "great captain usopp";

		ft_striteri(s, NULL);
		char *expected = "great captain usopp";
		char *received = s;

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_striteri(\"%s\", NULL)\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_striteri\n");
}
