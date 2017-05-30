#include "ft_printf.h"

int main()
{
	char *big;
	char *little;
	char *replace;
	int num1;
	long double num2;

	num1 = 10203;
	num2 = 3.1415962;
	big = ft_strdup("is that%s that%s bad%d?\n%llx");
	little = ft_strdup("HOLLA\n");
	replace = ft_strdup("No No\n");
	ft_printf(big, little, replace, num1, num2);
}
