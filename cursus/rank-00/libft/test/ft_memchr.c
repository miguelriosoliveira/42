#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main()
{
	{
		char *s = "great captain usopp";
		char c = 'u';
		int n = 16;

		char *expected = memchr(s, c, n);
		char *received = ft_memchr(s, c, n);

		int passed = strcmp(expected, received) == 0;
		if (!passed)
		{
			char *result = passed ? "✅" : "❌";
			printf("%s ft_memchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = "great captain usopp";
		char c = 'z';
		int n = 5;

		char *expected = memchr(s, c, n);
		char *received = ft_memchr(s, c, n);

		int passed = expected == received; // NULL
		if (!passed)
		{
			char *result = passed ? "✅" : "❌";
			printf("%s ft_memchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s = "great captain usopp";
		char c = '\0';
		int n = 50;

		char *expected = memchr(s, c, n);
		char *received = ft_memchr(s, c, n);

		int passed = expected == received; // NULL
		if (!passed)
		{
			char *result = passed ? "✅" : "❌";
			printf("%s ft_memchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char s[] = {0, 1, 2, 3, 4, 5};
		int c = 0;
		int n = 0;

		char *expected = memchr(s, c, n);
		char *received = ft_memchr(s, c, n);

		int passed = expected == received; // NULL
		if (!passed)
		{
			char *result = passed ? "✅" : "❌";
			printf("%s ft_memchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char s[] = {0, 1, 2, 3, 4, 5};
		int c = 0;
		int n = 1;

		char *expected = memchr(s, c, n);
		char *received = ft_memchr(s, c, n);

		int passed = expected == received; // NULL
		if (!passed)
		{
			char *result = passed ? "✅" : "❌";
			printf("%s ft_memchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char s[] = {0, 1, 2, 3, 4, 5};
		int c = 2 + 256;
		int n = 3;

		char *expected = memchr(s, c, n);
		char *received = ft_memchr(s, c, n);

		int passed = expected == received; // NULL
		if (!passed)
		{
			char *result = passed ? "✅" : "❌";
			printf("%s ft_memchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char s[] = {-49, 49, 1, -1, 0, -2, 2};
		int c = -1;
		int n = 7;

		char *expected = memchr(s, c, n);
		char *received = ft_memchr(s, c, n);

		int passed = expected == received; // NULL
		if (!passed)
		{
			char *result = passed ? "✅" : "❌";
			printf("%s ft_memchr(\"%s\")\n", result, s);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_memchr\n");
}
