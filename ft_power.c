#include "libft.h"

long double	ft_power(long long power, long long base)
{
	int		sign;
	long long	counter;
	long double	ret;

	ret = 1;
	counter = 0;
	sign = 0;
	if (!power)
		return (1);
	if (power < 0)
	{
		sign = -1;
		power *= -1;
	}
	while (counter < power)
	{
		ret *= base;
		++counter;
	}
	if (sign == -1)
		ret = 1 / ret;
	return (ret);
}
