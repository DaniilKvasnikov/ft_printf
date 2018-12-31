
#include "rgyles.h"
#include <stdio.h>

int		ft_c(t_spec *elem, va_list ap)
{
	int size;
	char c;

	size = 1;
	while (size < elem->width && !elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}
	c = (unsigned int)va_arg(ap, int);
	ft_putchar(c);
	while (size < elem->width && elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}
	return (size);
}
