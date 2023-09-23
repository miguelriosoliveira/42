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
		char *s = "great captain usopp";

		char *filename = "test/ft_putstr_fd.txt";
		int fd = open(filename, O_CREAT | O_WRONLY, S_IRWXU);
		ft_putstr_fd(s, fd);
		close(fd);

		char *expected = s;
		char *received = read_file(filename);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_putstr_fd(\"%s\", %d)\n", result, s, fd);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_putstr_fd\n");
}
