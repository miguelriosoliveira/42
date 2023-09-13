#include <stdio.h>
#include "includes/ft.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("missing an argument\n");
		return 0;
	}
	printf("argv[1]: \"%s\" (length: %d)\n", argv[1], ft_strlen(argv[1]));
	return 0;
}
