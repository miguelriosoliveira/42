#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	{
		char *s = "great captain usopp";
		char c = 'u';

		char *expected = strrchr(s, c);
		char *received = ft_strrchr(s, c);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strrchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = "great captain usopp";
		char c = 'z';

		char *expected = strrchr(s, c);
		char *received = ft_strrchr(s, c);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strrchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = "great captain usopp";
		char c = '\0';

		char *expected = strrchr(s, c);
		char *received = ft_strrchr(s, c);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strrchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char s[10] = "123456789";
		char c = 'a';

		char *expected = strrchr(s, c);
		char *received = ft_strrchr(s, c);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strrchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char s[10];
		s[0] = '1';
		s[1] = '2';
		s[2] = '3';
		s[3] = '4';
		s[4] = '5';
		s[5] = '\0';
		s[6] = '\0';
		s[7] = 'a';
		s[8] = '\0';
		s[9] = '\0';
		char c = '\0';

		char *expected = strrchr(s, c);
		char *received = ft_strrchr(s, c);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strrchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = "tripouille";
		int c = 't' + 256;

		char *expected = strrchr(s, c);
		char *received = ft_strrchr(s, c);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strrchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_strrchr\n");
}
