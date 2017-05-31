#include "ft_printf.h"

int main(int argc, char **argv)
{
	char *str = ft_strdup("hello%s");
	char *str2 = ft_strdup("nonono\n");
	ft_printf(str, str2);
	return (1);
}
