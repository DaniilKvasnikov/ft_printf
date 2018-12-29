
#include "rgyles.h"
#include <stdio.h>

int		ft_u(t_spec *elem, va_list ap)
{
	char *str;
	int size;

	str = ft_itoa(va_arg(ap, int));
	size = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (size);
}
