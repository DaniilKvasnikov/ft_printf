
#include "libft.h"

void	ft_toupper_str(char *str)
{
	int index;

	index = -1;
	while (str[++index] != '\0')
		str[index] = ft_toupper(str[index]);
}
