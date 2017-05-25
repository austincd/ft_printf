/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 09:00:43 by exam              #+#    #+#             */
/*   Updated: 2017/05/18 22:07:14 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_charcat(char *str, char c)
{
	if (str)
	{
		while (*str)
			++str;
		*str = c;
	}
}

static int	ft_numlen_base(long long num, int base)
{
	int counter;

	counter = 0;
	if (!num)
		return (1);
	while (num)
	{
		num /= base;
		++counter;
	}
	return (counter);
}

static void	ft_itoa_internal(char *str, long long num, int base)
{
	char	digits[17];

	ft_strlcpy(digits, "0123456789ABCDE", 17);
	if (str)
	{
		if (num < base)
			ft_charcat(str, digits[num]);
		else if (num >= base)
		{
			ft_itoa_internal(str, num / base, base);
			ft_itoa_internal(str, num % base, base);
		}
	}
}

char		*ft_itoa_base(int value, int base)
{
	long long	val;
	int		length;
	char		*new;

	val = value;
	new = NULL;
	if (base >= 2 && base <= 16)
	{
		if (val < 0)
		{
			val *= -1;
			if (base == 10)
			{
				length = ft_numlen_base(val, base) + 1;
				new = ft_strnew(length);
				ft_charcat(new, '-');
			}
		}
		length = ft_numlen_base(val, base);
		if (!new)
			new = ft_strnew(length);	
		ft_itoa_internal(new, val, base);
	}
	return (new);
}
