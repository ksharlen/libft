#include "libft.h"

static int	my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
		if (NUM_CMP(*s1, *s2))
			return (*s1 - *s2);
		else
			s1++ && s2++;
}

int		main(void)
{
	char *str1 = "";
	char *str2 = "132";
	int	cmp;

	cmp = ft_strcmp(str1, str2);
	printf("cmp = %d\n", cmp);

	cmp = my_strcmp(str1, str2);
	printf("cmp = %d\n", cmp);
	return (0);
}
