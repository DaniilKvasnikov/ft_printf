
#include "rgyles.h"
#include <stdio.h>

int		ft_i(t_spec *elem, va_list ap)
{
	char *str;
	int size;

	str = ft_itoa(va_arg(ap, int));
	size = ft_output(elem, str, ft_strlen(str));
	free(str);
	return (size);
}
