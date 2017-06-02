#include "libft.h"

char	*ft_basefloat(long double num, int base)
{
	char	*str;
	int		counter;
	long double power;

	power = 1;
	counter = 0;
	str = NULL;
	while (num / power >= base)
	{
		power = ft_power(counter, base);
		++counter;
	}
	while (num / power >= base)
	{
		ft_charcat(str, digits[num / power]);
		num = ft_floatmod(num, power);
		power = ft_power(--counter, base);
	}
	while (counter < 9)
	{
		
		++counter;
	}
}
