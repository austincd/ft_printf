#include "ft_printf.h"

int main(int argc, char **argv)
{
//	char *str = ft_strdup("%+ d %+p for po%+inter\n");
//	char *str = ft_strdup("%+d\n");
//	char *str = ft_strdup("%+i\n");
//	char *str = ft_strdup("%*.*s\n");
//	char *str = ft_strdup("%+04d\n");
	long long *one;
	long double num = 0.1;
	one = (long long*)&num;
	printf("%d\n", sizeof(long long));
	printf("one\n%lld\n two\n%lld\n", one[0],one[1]);
//	ft_printf(str, 4, 4, "hello");
//	ft_printf(str, 10, ft_strdup("@@"), 20);
	return (1);
}
