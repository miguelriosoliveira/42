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
		char *s = "great captain usopp";

		char *filename = "test/ft_putendl_fd.txt";
		int fd = open(filename, O_CREAT | O_WRONLY, S_IRWXU);
		ft_putendl_fd(s, fd);
		close(fd);

		char *expected = "great captain usopp\n";
		char *received = read_file(filename);

		int passed = strcmp(expected, received) == 0;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_putendl_fd(\"%s\", %d)\n", result, s, fd);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}
	}

	printf("✅ ft_putendl_fd\n");
}
