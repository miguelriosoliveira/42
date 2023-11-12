#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "../get_next_line.h"

int main(void) {
	char *filename = "test/file.txt";

	FILE *fp = fopen(filename, "r");
    char *expected = NULL;
    size_t len = 0;
	getline(&expected, &len, fp);

	int fd = open(filename, O_RDONLY);
	char *received = get_next_line(fd);

	int passed = strcmp(expected, received) == 0;
	if (!passed) {
		char *result = passed ? "✅" : "❌";
		printf("%s get_next_line(\"%s\"): \"%s\"\n", result, filename, received);
		printf("expected: \"%s\"\n", expected);
		printf("received: \"%s\"\n", received);
		return 1;
	}

	printf("✅ PASSED\n");
}
