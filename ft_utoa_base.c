/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 09:00:43 by exam              #+#    #+#             */
/*   Updated: 2017/05/26 22:34:59 by adaly            ###   ########.fr       */
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

static int	ft_numlen_base(unsigned long long num, unsigned int base)
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

static void	ft_utoa_internal(char *str, unsigned long long num, unsigned int base)
{
	char	digits[17];

	ft_strlcpy(digits, "0123456789ABCDE", 17);
	if (str)
	{
		if (num < base)
			ft_charcat(str, digits[num]);
		else if (num >= base)
		{
			ft_utoa_internal(str, num / base, base);
			ft_utoa_internal(str, num % base, base);
		}
	}
}

char		*ft_utoa_base(unsigned long long val, unsigned int base)
{
	int		length;
	char		*new;

	new = NULL;
	if (base >= 2 && base <= 16)
	{
		length = ft_numlen_base(val, base);
		if (!new)
			new = ft_strnew(length);	
		ft_utoa_internal(new, val, base);
	}
	return (new);
}
