#include "libft.h"

long double		ft_floatmod(long double alpha, long double beta)
{
	long double		temp;
	long long		counter;

	temp = 0;
	counter = 0;
	while (alpha - temp >= 0)
	{
		temp = beta * counter;
		++counter;
	}
	if (alpha - temp < 0)
		temp = beta * (counter - 2);
	return (alpha - temp);
}
