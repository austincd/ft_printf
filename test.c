#include "ft_printf.h"

int main()
{
	void *ptr;
	char *str;
	char *temp;

	ptr = ft_memalloc(sizeof(int));
	temp = ft_utoa_base((long long)ptr, 16);
	str = ft_strjoin("0x", temp);
	printf("%s\n%lu\n%p\n%s\n%llx\n", temp, sizeof(long long), ptr, str, (long long)ptr);
}
