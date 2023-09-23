#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include "../libft.h"

char *read_file(char *filename) {
	int fd = open(filename, O_RDONLY);
	char buffer[100];
	read(fd, buffer, sizeof(buffer));
	close(fd);
	return strdup(buffer);
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
