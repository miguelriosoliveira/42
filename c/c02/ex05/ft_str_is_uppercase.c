int ft_str_is_uppercase(char *str) {
	int i = 0;
	while (str[i]) {
		int is_uppercase = str[i] >= 'A' && str[i] <= 'Z';
		if (!is_uppercase) {
			return 0;
		}
		i++;
	}

	return 1;
}

#include <stdio.h>

int main(void) {
	char* word = "lowercase";
	printf("\"%s\" is uppercase? %d\n", word, ft_str_is_uppercase(word));

	word = "UPPERCASE";
	printf("\"%s\" is uppercase? %d\n", word, ft_str_is_uppercase(word));

	word = "EmOcAsE";
	printf("\"%s\" is uppercase? %d\n", word, ft_str_is_uppercase(word));

	word = "";
	printf("\"%s\" is uppercase? %d\n", word, ft_str_is_uppercase(word));

	return 0;
}

