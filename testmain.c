#include "ft_printf.h"

int main(int argc, char **argv)
{
	char *str = ft_strdup("Kashim a %c histoires à raconter");
	ft_printf(str, '\0');
	return (1);
}
