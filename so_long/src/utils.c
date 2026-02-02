#include "../include/so_long.h"

int	len(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	ft_strlcmp(char *s1, char *s2, int max)
{
	int	i;

	i = 0;
	while ((i < max) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = 0;
}
