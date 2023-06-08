int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int  ft_strlcat(char *dest, char *src, unsigned int size)
{
  unsigned int	i;
	int				dest_len;
	int				src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
  if (size == 0)
    return (dest_len + src_len);
	while (i < size - dest_len && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}