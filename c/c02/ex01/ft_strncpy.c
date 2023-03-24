char *ft_strncpy(char *dest, char *src, unsigned int n) {
	unsigned int i = 0;
	while (i < n) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

#include <stdio.h>
#include <string.h>

int main(void) {
	char src[]  = "source";
	char dest[7];
	
	printf("#ft_strncpy\n");
	printf("\n");
	printf("Antes:\n");
	printf("src:  \"%s\"\n", src);
	printf("dest: \"%s\"\n", dest);
	
	ft_strncpy(dest, src, 4);
	
	printf("\n");
	printf("Luego:\n");
	printf("src:  \"%s\"\n", src);
	printf("dest: \"%s\"\n", dest);
	
	// ----------------------------
	
	char src2[]  = "source";
	char dest2[7];
	
	printf("\n");
	printf("#strncpy\n");
	printf("\n");
	printf("Antes:\n");
	printf("src2:  \"%s\"\n", src2);
	printf("dest2: \"%s\"\n", dest2);

	strncpy(dest2, src2, 4);
	
	printf("\n");
	printf("Luego:\n");
	printf("src2:  \"%s\"\n", src2);
	printf("dest2: \"%s\"\n", dest2);

	return 0;
}

