#include <stdio.h>
#include <string.h>
#include "../ft_printf.h"

char *escape(char *str) {
	char buf[9999];
	size_t bp = 0;

	for (size_t sp = 0; str[sp]; sp++) {
		if (!ft_isprint(str[sp]))
			buf[bp++] = '\\';
		switch (str[sp]) {
			case '\n':
				buf[bp++] = 'n';
				break;
			case '\t':
				buf[bp++] = 't';
				break;
			default:
				buf[bp++] = str[sp];
				break;
		}
	}
	buf[bp] = 0;

	return strdup(buf);
}

int main() {
	{
		char *format = "king of pirates\n";
		printf("[   printf] ");
		int expected = printf("king of pirates\n");
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_printf(\"%s\"): %d\n", result, escape(format), received);
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}
	}
	{
		char *format = "great %captain usopp\n";
		char param = 'c';
		printf("[   printf] ");
		int expected = printf("great %captain usopp\n", param);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, param);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_printf(\"%s\"): %d\n", result, escape(format), received);
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}
	}
	{
		char *format = "the %s hunter\n";
		char *param = "pirate";
		printf("[   printf] ");
		int expected = printf("the %s hunter\n", param);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, param);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_printf(\"%s\"): %d\n", result, escape(format), received);
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}
	}
	{
		char *format = "the %s hunter\n";
		char *param = "";
		printf("[   printf] ");
		int expected = printf("the %s hunter\n", param);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, param);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_printf(\"%s\"): %d\n", result, escape(format), received);
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}
	}
	{
		char *format = "this is a pointer address: %p\n";
		char *param = "pointer";
		printf("[   printf] ");
		int expected = printf("this is a pointer address: %p\n", param);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, param);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_printf(\"%s\"): %d\n", result, escape(format), received);
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}
	}

	printf("✅ ft_printf\n");
}
