
#include "rgyles.h"
#include <stdio.h>

int		ft_c(t_spec *elem, va_list ap)
{
	int size;
	char c;
	char *str;

	size = 1;
	str = ft_strnew(2);
	str[0] = (unsigned int)va_arg(ap, int);
	size = ft_output(elem, str, size);
	return (size);
}
