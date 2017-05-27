#include "ft_printf.h"

int main()
{
	char *big;
	char *little;
	char *replace;

	big = ft_strdup("is that that bad?");
	little = ft_strdup("that");
	replace = ft_strdup("THAT");
	ft_find_replace_after(&big, little, replace, 7);
	printf("%s\n", big);
}
