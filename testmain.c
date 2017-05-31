#include "ft_printf.h"

int main(int argc, char **argv)
{
	char *str = ft_strdup("@%ls\n");
	ft_printf(str, ft_strdup("@"));
	return (1);
}
