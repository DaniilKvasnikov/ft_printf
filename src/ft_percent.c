
#include "rgyles.h"
#include <stdio.h>

int		ft_percent(t_spec *elem, va_list ap)
{
	int	size;
	(void)ap;
	size = ft_output(elem, "%", 1);
	return (size);
}
