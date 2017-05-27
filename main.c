#include "ft_printf.h"

int main()
{
	char *str;
	unsigned int new;

	str = ft_strdup("%%");
	ft_printf(str);
}
