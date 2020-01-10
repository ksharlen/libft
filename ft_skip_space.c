#include "libft.h"

const char	*ft_skip_space(const char *str)
{
	if (str && *str)
	{
		while (*str && *str == ' ')
			++str;
	}
	return (str);
}
