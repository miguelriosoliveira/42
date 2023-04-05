int ft_str_is_printable(char *str) {
	int i = 0;
	while (str[i]) {
		int is_printable = str[i] >= 32 && str[i] <= 127;
		if (!is_printable) {
			return 0;
		}
		i++;
	}

	return 1;
}

#include <stdio.h>

int main(void) {
	char* word = "lowercase";
	printf("\"%s\" is printable? %d\n", word, ft_str_is_printable(word));

	word = "UPPERCASE";
	printf("\"%s\" is printable? %d\n", word, ft_str_is_printable(word));

	word = "EmOcAsE";
	printf("\"%s\" is printable? %d\n", word, ft_str_is_printable(word));

	word = "";
	printf("\"%s\" is printable? %d\n", word, ft_str_is_printable(word));

	word = "\n";
	printf("\"%s\" is printable? %d\n", word, ft_str_is_printable(word));

	return 0;
}

