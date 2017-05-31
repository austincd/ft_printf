#include "ft_printf.h"

int main(int argc, char **argv)
{
//	char *str = ft_strdup("%+ d %+p for po%+inter\n");
//	char *str = ft_strdup("%+d\n");
//	char *str = ft_strdup("%+i\n");
	char *str = ft_strdup("%+04d\n");
//	char *str = ft_strdup("%+04d\n");
	ft_printf(str, 42);
//	ft_printf(str, 10, ft_strdup("@@"), 20);
	return (1);
}
