int ft_str_is_numeric(char *str) {
	int i = 0;
	while (str[i]) {
		int is_numeric = str[i] >= '0' && str[i] <= '9';
		if (!is_numeric) {
			return 0;
		}
		i++;
	}

	return 1;
}

#include <stdio.h>

int main(void) {
	char* word = "12345";
	printf("\"%s\" is numeric? %d\n", word, ft_str_is_numeric(word));
	
	word = "1234a";
	printf("\"%s\" is numeric? %d\n", word, ft_str_is_numeric(word));
	
	word = "";
	printf("\"%s\" is numeric? %d\n", word, ft_str_is_numeric(word));
	
	word = "3[4";
	printf("\"%s\" is numeric? %d\n", word, ft_str_is_numeric(word));

	return 0;
}
