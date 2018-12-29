
#include "rgyles.h"
#include <stdio.h>
#include "libft.h"

char	*ft_dtoa(double n)
{
	char *str;
	char *dop;
	char *res;
	int i;

	str = ft_itoa(n / 1);
	dop = ft_strnew(7);
	dop[0] = '.';
	i = 0;
	while (n > 1)
		n -= 1;
	while (++i < 7)
	{
		n *= 10.0;
		dop[i] = (n / 1) + '0';
		while (n > 1)
			n -= 1;
	}
	res = ft_strnew(ft_strlen(str) + ft_strlen(dop));
	ft_strcpy(res, str);
	ft_strcpy(res + ft_strlen(str), dop);
	free(str);
	free(dop);
	return (res);
}

int		ft_f(t_spec *elem, va_list ap)
{
	char	*str;
	int		size;

	str = ft_dtoa(va_arg(ap, double));
	size = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (size);
}
