#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "../get_next_line.h"

int	compare_results(int bytes_read, char *r1, char *r2) {
	if (r1 && r2) {
		return strcmp(r1, r2) == 0;
	}
	return ((bytes_read == -1) && !r2);
}

int main(int argc, char **argv) {
	if (argc) {}

	int filecount = argc - 1;
	char **filenames = argv + 1;
	FILE *fp_list[filecount];
	int fd_list[filecount];
	int i;

	i = 0;
	printf("File count: %d\n", filecount);
	while (i < filecount) {
		char *filename = filenames[i];
		printf("File %d: \"%s\"\n", i + 1, filename);
		fp_list[i] = fopen(filename, "r");
		fd_list[i] = open(filename, O_RDONLY);
		i++;
	}

	int line_count = 0;
	i = 0;
	char *expected = NULL;
	size_t len = 0;
	int bytes_read = 0;
	// int MAX_LINES = 32109;
	// int MAX_LINES = 10703;
	int MAX_LINES = 10 * filecount;
	while (MAX_LINES--) {
		char *filename = filenames[i];

		FILE *fp = fp_list[i];
		int fd = fd_list[i];

		bytes_read = getline(&expected, &len, fp);
		char *received = get_next_line(fd);

		if (bytes_read == -1 && !received) {
			if (strcmp(filename, "test/hp1.txt") == 0) {
				printf("EOF on \"%s\"\n", filename);
			}
		}

		printf("============ \"%s\" ============\n", filename);
		printf("expected: \"%s\"\n", expected);
		printf("received: \"%s\"\n", received);

		int passed = compare_results(bytes_read, expected, received);
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s get_next_line(\"%s\") on line %d: \"%s\"\n", result, filename, line_count, received);
			printf("expected: \"%s\"\n", expected);
			printf("received: \"%s\"\n", received);
			return 1;
		}

		line_count++;
		i = (i + 1) % filecount;
	}

	i = 0;
	while (i < filecount) {
		fclose(fp_list[i]);
		close(fd_list[i]);
		i++;
	}

	printf("✅ GNL BONUS OK with BUFFER_SIZE=%d\n", BUFFER_SIZE);
}
