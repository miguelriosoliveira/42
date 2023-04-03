int ft_str_is_alpha(char *str) {
	int i = 0;
	while (str[i]) {
		int is_upper_case = str[i] >= 'A' && str[i] <= 'Z';
		int is_lower_case = str[i] >= 'a' && str[i] <= 'z';
		if (!is_upper_case && !is_lower_case) {
			return 0;
		}
		i++;
	}
	return 1;
}

#include <stdio.h>

int main(void) {
	char* alpha_word = "yes";
	printf("\"%s\" is alpha? %d\n", alpha_word, ft_str_is_alpha(alpha_word));
	
	char* not_alpha_word = "yes1";
	printf("\"%s\" is alpha? %d\n", not_alpha_word, ft_str_is_alpha(not_alpha_word));
	
	return 0;
}

