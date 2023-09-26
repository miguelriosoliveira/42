#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include "../libft.h"

char *read_file(char *filename) {
	char * buffer = 0;
	long length;
	FILE * f = fopen (filename, "rb");

	if (f)
	{
		fseek (f, 0, SEEK_END);
		length = ftell (f);
		fseek (f, 0, SEEK_SET);
		buffer = malloc (length);
		if (buffer)
		{
			fread (buffer, 1, length, f);
		}
		fclose (f);
	}
	return buffer;
}

int main() {
	{
		int n = 123;

		char *filename = "test/ft_putnbr_fd.txt";
		int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		ft_putnbr_fd(n, fd);
		close(fd);

		char *expected = "123";
		char *received = read_file(filename);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_putnbr_fd(%d, %d)\n", result, n, fd);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}
	{
		int n = -1234;

		char *filename = "test/ft_putnbr_fd.txt";
		int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		ft_putnbr_fd(n, fd);
		close(fd);

		char *expected = "-1234";
		char *received = read_file(filename);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_putnbr_fd(%d, %d)\n", result, n, fd);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_putnbr_fd\n");
}
