#include "ft_printf.h"

int main(int argc, char **argv)
{
	char *str = ft_strdup("%+ d %+p for po%+inter\n");
	ft_printf(str, 10, ft_strdup("@@"), 20);
	return (1);
}
