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
		char *format = "-%c-%c-%c-\n";
		char param1 = '0';
		int param2 = 0;
		char param3 = '1';

		printf("[   printf] %d\n", printf(""));
		printf("[   printf] %d\n", printf("%c", 0));

		printf("[   printf] ");
		int expected = printf(format, param1, param2, param3);
		ft_putstr_fd("[ft_printf] ", 1);
		int received = ft_printf(format, param1, param2, param3);

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
		char *format = "char [%12c]\n";
		char param = 'Z';
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
		char *format = "char [%012c]\n";
		char param = 'Z';
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
		char *format = "char [%-12c]\n";
		char param = 'Z';
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
		char *format = "char [%-012c]\n";
		char param = 'Z';
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
		char *format = " str [%12s]\n";
		char *param = "42";
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
		char *format = " str [%-12s]\n";
		char *param = "42";
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
		char *format = " str [%012s]\n";
		char *param = "42";
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
		char *format = " str [%-012s]\n";
		char *param = "42";
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
		char *format = " str [%.5s]\n";
		char *param = "1234567890";
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
		char *format = " str [%.4s]\n";
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
		char *format = " str [%12.4s]\n";
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
		char *format = " str [%-12.4s]\n";
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
		char *format = " str [%012.4s]\n";
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
		char *format = " str [%-012.4s]\n";
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
		char *format = " str [%.s]\n";
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
		char *format = " str [%.09s]\n";
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
		char *format = " ptr [%22p]\n";
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
		char *format = " ptr [%022p]\n";
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
		char *format = " ptr [%-22p]\n";
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
		char *format = " ptr [%-022p]\n";
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
		char *format = " nbr [%12d]\n";
		int param = -14523;
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
		char *format = " nbr [%-12d]\n";
		int param = -14523;
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
		char *format = " nbr [%012d]\n";
		int param = -14523;
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
		char *format = " nbr [%-012d]\n";
		int param = -14523;
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
		char *format = " nbr [%12.9d]\n";
		int param = -14523;
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
		char *format = " nbr [%-12.9d]\n";
		int param = -14523;
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
		char *format = " nbr [%012.9d]\n";
		int param = -14523;
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
		char *format = " nbr [%-012.9d]\n";
		int param = -14523;
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
		char *format = " nbr [%.5d]\n";
		int param = 14523;
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

	printf("✅ ft_printf\n");
}
