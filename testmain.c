#include "ft_printf.h"

int main(int argc, char **argv)
{
	char *str = ft_strdup("Kashim a %10d hi%d %istoires à raconter\n");
	ft_printf(str, 100, 200, 300);
	return (1);
}
