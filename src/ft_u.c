
#include "rgyles.h"
#include <stdio.h>

int		ft_u(t_spec *elem, va_list ap)
{
	int size;
	unsigned long long int n;
	char *tmp;
	char *str;

	n = va_arg(ap, unsigned long long int);
	if (elem->length.l == 1)
		n = (unsigned long int)n;
	else if (elem->length.l == 2)
		n = (unsigned long int)n;
	else if (elem->length.j == 1)
		n = (uintmax_t)n;
	else
		n = (unsigned int)n;
	str = ft_itoa_ui(n);
	if (elem->precision != -1 && elem->precision > (int)ft_strlen(str))
	{
		tmp = str;
		str = ft_precision(str, elem->precision);
		free(tmp);
	}
	size = ft_output(elem, str, ft_strlen(str));
	free(str);
	return (size);
}
