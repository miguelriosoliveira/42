#include <stdio.h>
#include <string.h>
#include <limits.h>
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
		#pragma clang diagnostic ignored "-Wformat-security"
		int expected = printf(format);
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
		int expected = printf(format, param);
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
		int expected = printf(format, param);
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
		int expected = printf(format, param);
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
		char *format = "NULL %s NULL\n";
		char *param = NULL;
		printf("[   printf] ");
		int expected = printf(format, param);
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
		int expected = printf(format, param);
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
		char *format = "this is a very weird pointer address: %p\n";
		char *param = (void *)-14523;
		printf("[   printf] ");
		int expected = printf(format, param);
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
		char *format = "Chopper's current bounty is %d berries\n";
		int param = 1000;
		printf("[   printf] ");
		int expected = printf(format, param);
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
		char *format = "Drum's average temperature is around %i°C\n";
		int param = -45;
		printf("[   printf] ");
		int expected = printf(format, param);
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
		char *format = "The lowest temperature ever recorded is %u°C... Wait, is that right?\n";
		int param = -89;
		printf("[   printf] ");
		int expected = printf(format, param);
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
		char *format = "This is %d in hexadecimal: %x\n";
		int param = 51966;
		printf("[   printf] ");
		int expected = printf(format, param, param);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, param, param);

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
		char *format = "This is %d in hexadecimal: %x\n";
		int param = -42;
		printf("[   printf] ");
		int expected = printf(format, param, param);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, param, param);

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
		char *format = "THIS IS %d IN HEXADECIMAL: %X\n";
		int param = 12648430;
		printf("[   printf] ");
		int expected = printf(format, param, param);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, param, param);

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
		char *format = "THIS IS %d IN HEXADECIMAL: %X\n";
		int param = -42;
		printf("[   printf] ");
		int expected = printf(format, param, param);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, param, param);

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
		char *format = "This is the percent symbol: %%\n";
		printf("[   printf] ");
		int expected = printf(format);
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
		char *format = "This is madness: %c %s %p %d %i %u %x %X %%\n";
		printf("[   printf] ");
		char c = 'c';
		char *s = "string";
		void *p = s;
		int d = 42;
		int i = -42;
		unsigned int u = -42;
		int x = 51966;
		int X = 12648430;
		int expected = printf(format, c, s, p, d, i, u, x, X);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, c, s, p, d, i, u, x, X);

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
		char *format = "";
		printf("[   printf] \"");
		int expected = printf(format);
		printf("\"\n");
		ft_putstr_fd("[ft_printf] \"", 1);
		int received = ft_printf(format);
		ft_putstr_fd("\"\n", 1);

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
		char *format = "%X\n";
		printf("[   printf] ");
		int expected = printf(format, INT_MAX);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, INT_MAX);

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
		char *format = "%d\n";
		printf("[   printf] ");
		int expected = printf(format, INT_MAX);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, INT_MAX);

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
		char *format = "%X\n";
		printf("[   printf] ");
		int expected = printf(format, INT_MIN);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, INT_MIN);

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
		char *format = "%d\n";
		printf("[   printf] ");
		int expected = printf(format, INT_MIN);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, INT_MIN);

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
		char *format = "\001\002\007\v\010\f\r\n";
		printf("[   printf] ");
		int expected = printf(format);
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

	printf("✅ ft_printf\n");
}
