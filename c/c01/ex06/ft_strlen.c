#include <stdio.h>

int ft_strlen(char *str) {
	int count = 0;
	while (str[count]) {
		count++;
	}
	return count;
}

int main(void) {
	char* word = "0123456789";
	int len = ft_strlen(word);
	printf("La palabra \"%s\" tiene %d caracteres.", word, len);
	return 0;
}

