char *ft_strcpy(char *dest, char *src) {
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

#include <stdio.h>
#include <string.h>

int main(void) {
	char src[]  = "source1";
	char dest[8];
	
	printf("#ft_strcpy\n");
	printf("\n");
	printf("Antes:\n");
	printf("src:  \"%s\"\n", src);
	printf("dest: \"%s\"\n", dest);
	
	ft_strcpy(dest, src);
	
	printf("\n");
	printf("Luego:\n");
	printf("src:  \"%s\"\n", src);
	printf("dest: \"%s\"\n", dest);
	
	// ----------------------------
	
	char src2[]  = "source2";
	char dest2[8];
	
	printf("\n");
	printf("#strcpy\n");
	printf("\n");
	printf("Antes:\n");
	printf("src2:  \"%s\"\n", src2);
	printf("dest2: \"%s\"\n", dest2);

	strcpy(dest2, src2);
	
	printf("\n");
	printf("Luego:\n");
	printf("src2:  \"%s\"\n", src2);
	printf("dest2: \"%s\"\n", dest2);
	
	return 0;
}

