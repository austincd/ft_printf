#include "libft.h"

int main()
{
	long double num;
	int base;
	char *str;

	num = 15.5 / 8;
	base = 16;
	str = ft_basefloat(num, base);
	printf("str is %s\n", str);
}
