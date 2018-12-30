#include "libft.h"

static int	get_size(long long n, int base)
{
	int index;

	index = 0;
	while (n > 0)
	{
		index++;
		n /= base;
	}
	return (index);
}

char		*ft_rebase(long long n, int base)
{
	char	*str = "0123456789abcdef";
	char	*res;
	int		index;

	if ((res = (char *)malloc(sizeof(char) * (get_size(n, base) + 1))) == NULL)
		return (NULL);
	index = get_size(n, base) + 1;
	res[--index] = '\0';
	if (n == 0)
		res[index] = '0';
	while (n > 0)
	{
		res[--index] = str[n % base];
		n /= base;
	}
	return (res);
}
