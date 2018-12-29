
#include "rgyles.h"
#include <stdio.h>

int		ft_o(t_spec *elem, va_list ap)
{
	char	*par;
	int		size;

	if ((par = ft_rebase(va_arg(ap, int), 8)) == NULL)
		return (-1);
	ft_putstr(par);
	size = ft_strlen(par);
	free(par);
	return (size);
}
