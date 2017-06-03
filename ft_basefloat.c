#include "libft.h"

char	*ft_basefloat(long double num, int base)
{
	char	*str;
	int		counter;
	long double power;
	char		*digits;
	int			sign;

	digits = ft_strdup("0123456789ABCDEF");
	power = 1;
	counter = 0;
	str = NULL;
	if (num < 0)
	{
		sign = -1;
		num *= -1;
	}
	while (num / power >= base)
	{
		power = ft_power(counter, base);
		++counter;
	}
	str = ft_strnew(counter + 9);
	if (sign == -1)
		ft_charcat(str, '-');
	while (num >= 0.000000000000000001)
	{
		ft_charcat(str, digits[(long long)((num / power))]);
		if (power == 1)
			ft_charcat(str, '.');
		num = ft_floatmod(num, power);
		power = ft_power(--counter, base);
	}
	return (str);
}
