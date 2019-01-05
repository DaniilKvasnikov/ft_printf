
#include "rgyles.h"
#include <stdio.h>

int		ft_p(t_spec *elem, va_list ap)
{
	int		size;
	char	*ans;
	char	*p;

	if ((p = ft_rebase((long long)va_arg(ap, void*), 16)) == NULL)
		return (-1);
	if ((ans = ft_strjoin("0x", p)) == NULL)
	{
		free(p);
		return (-1);
	}
	size = ft_output(elem, ans, 0); 
	ft_bzero(p, ft_strlen(p));
	ft_bzero(ans, ft_strlen(ans));
	free(p);
	free(ans);
	return (size);
}
