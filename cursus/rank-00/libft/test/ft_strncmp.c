#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	{
		char *s1 = "great captain usopp";
		char *s2 = "great captain usopp";
		char n = 9;

		int expected = strncmp(s1, s2, n);
		int received = ft_strncmp(s1, s2, n);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strncmp(\"%s\", \"%s\", %d)\n", result, s1, s2, n);
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}
	}
	{
		char *s1 = "\x12\xff\x65\x12\xbd\xde\xad";
        char *s2 = "\x12\x02";
		char n = 6;

		int expected = strncmp(s1, s2, n);
		int received = ft_strncmp(s1, s2, n);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strncmp(\"%s\", \"%s\", %d)\n", result, s1, s2, n);
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}
	}
	{
		char *s1 = "";
        char *s2 = "AAAAAA";
		char n = 6;

		int expected = strncmp(s1, s2, n);
		int received = ft_strncmp(s1, s2, n);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strncmp(\"%s\", \"%s\", %d)\n", result, s1, s2, n);
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}
	}
	{
		char *s1 = "test";
        char *s2 = "testss";
		char n = 7;

		int expected = strncmp(s1, s2, n);
		int received = ft_strncmp(s1, s2, n);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strncmp(\"%s\", \"%s\", %d)\n", result, s1, s2, n);
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}
	}
	{
		char *s1 = "zyxbcdefgh";
        char *s2 = "abcdwxyz";
		char n = 0;

		int expected = strncmp(s1, s2, n);
		int received = ft_strncmp(s1, s2, n);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strncmp(\"%s\", \"%s\", %d)\n", result, s1, s2, n);
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}
	}

	printf("✅ ft_strncmp\n");
}
