#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main() {
	{
		char *s1 = "great captain usopp   ";
		char *set = " ";

		char *expected = "great captain usopp";
		char *received = ft_strtrim(s1, set);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strtrim(\"%s\", \"%s\")\n", result, s1, set);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s1 = " -- king of pirates* * **";
		char *set = " -*";

		char *expected = "king of pirates";
		char *received = ft_strtrim(s1, set);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strtrim(\"%s\", \"%s\")\n", result, s1, set);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		char *s1 = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t  ";
		char *set = " \n\t";

		char *expected = "Hello \t  Please\n Trim me !";
		char *received = ft_strtrim(s1, set);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_strtrim(\"%s\", \"%s\")\n", result, s1, set);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_strtrim\n");
}
