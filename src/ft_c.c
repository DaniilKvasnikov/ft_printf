
#include "rgyles.h"
#include <stdio.h>

int		ft_c(t_spec *elem, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}
