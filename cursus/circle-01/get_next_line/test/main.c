#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "../get_next_line.h"

int main(void) {
	{
		char *filename = "test/file.txt";
		FILE *fp = fopen(filename, "r");
		char *expected = NULL;
		size_t len = 0;
		int fd = open(filename, O_RDONLY);
		int line_count = 0;
		while (getline(&expected, &len, fp) > 0) {
			line_count++;
			char *received = get_next_line(fd);
			int passed = strcmp(expected, received) == 0;
			if (!passed) {
				char *result = passed ? "✅" : "❌";
				printf("%s get_next_line(\"%s\") on line %d: \"%s\"\n", result, filename, line_count, received);
				printf("expected: \"%s\"\n", expected);
				printf("received: \"%s\"\n", received);
				return 1;
			}
		}
	}
	{
		char *filename = "test/hp1.txt";
		FILE *fp = fopen(filename, "r");
		char *expected = NULL;
		size_t len = 0;
		int fd = open(filename, O_RDONLY);
		int line_count = 0;
		while (getline(&expected, &len, fp) > 0) {
			line_count++;
			char *received = get_next_line(fd);
			int passed = strcmp(expected, received) == 0;
			if (!passed) {
				char *result = passed ? "✅" : "❌";
				printf("%s get_next_line(\"%s\") on line %d: \"%s\"\n", result, filename, line_count, received);
				printf("expected: \"%s\"\n", expected);
				printf("received: \"%s\"\n", received);
				return 1;
			}
		}
	}

	printf("✅ PASSED\n");
}
