int ft_str_is_lowercase(char *str) {
	int i = 0;
	while (str[i]) {
		int is_lowercase = str[i] >= 'a' && str[i] <= 'z';
		if (!is_lowercase) {
			return 0;
		}
		i++;
	}

	return 1;
}

#include <stdio.h>

int main(void) {
	char* word = "lowercase";
	printf("\"%s\" is lowercase? %d\n", word, ft_str_is_lowercase(word));
	
	word = "UPPERCASE";
	printf("\"%s\" is lowercase? %d\n", word, ft_str_is_lowercase(word));
	
	word = "EmOcAsE";
	printf("\"%s\" is lowercase? %d\n", word, ft_str_is_lowercase(word));
	
	word = "";
	printf("\"%s\" is lowercase? %d\n", word, ft_str_is_lowercase(word));

	return 0;
}

