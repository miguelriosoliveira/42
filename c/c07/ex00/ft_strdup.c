#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*copy;

	src_len = ft_strlen(src);
	copy = malloc(src_len * sizeof(char));
	ft_strcpy(copy, src);
	return (copy);
}

/*
#include <string.h>
#include <stdio.h>
int main(void) {
	char *src;

	src = "hola mundo";
	printf("   strdup(\"%s\"): \"%s\"\n", src,    strdup(src));
	printf("ft_strdup(\"%s\"): \"%s\"\n", src, ft_strdup(src));
	printf("\n");

	src = "";
	printf("   strdup(\"%s\"): \"%s\"\n", src,    strdup(src));
	printf("ft_strdup(\"%s\"): \"%s\"\n", src, ft_strdup(src));

	return 0;
}
*/