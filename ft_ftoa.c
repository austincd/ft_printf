/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:47:08 by adaly             #+#    #+#             */
/*   Updated: 2017/06/04 03:36:17 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(long double num)
{
	char	*str;
	int		counter;
	long double	power;
	char		*digits;
	int			sign;

	digits = ft_strdup("01234567890");
	power = 1;
	counter = 0;
	str = NULL;
	if (num < 0)
	{
		sign = -1;
		num *= -1;
	}
	while (num / power >= 10)
	{
		power = ft_power(counter, 10);
		++counter;
	}
	str = ft_strnew(counter + 9);
	if (sign == -1)
		ft_charcat(str, '-');
	while (num >= 0.000000000000000001 || counter > -7)
	{
		if (counter == -6)
			ft_charcat(str, digits[(long long)((num / power) + .5)]);			
		else
			ft_charcat(str, digits[(long long)((num / power) + .1)]);
			num = ft_floatmod(num, power);
		if (counter == 0)
			ft_charcat(str, '.');
		power = ft_power(--counter, 10);
	}
	return (str);
}
