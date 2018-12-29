
#include "rgyles.h"
#include <stdio.h>

int		ft_p(t_spec *elem, va_list ap)
{
	char *par;

	if ((par = ft_rebase((long long)va_arg(ap, void*), 16)) == NULL)
		return (-1);
	ft_putstr("0x");
	ft_putstr(par);
	free(par);
	return (0);
	ap = 0;
}
