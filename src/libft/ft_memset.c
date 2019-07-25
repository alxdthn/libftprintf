#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long	set;
	size_t			i;

	i = 0;
	if (n > 7)
	{
		set = 0;
		while (i < 7)
		{
			set = set | c;
			set <<= 8;
			i++;
		}
		i = 0;
		set = set | c;
		while (i < n / 8)
			((unsigned long *)s)[i++] = set;
	}
	i *= 8;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}
