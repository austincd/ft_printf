/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 05:09:48 by adaly             #+#    #+#             */
/*   Updated: 2017/05/17 05:03:14 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_float(long double num, int base)
{
	long long	integer;
	long long	decimal;
	long long	temp2;
	long double	temp;
	char		*new;

	integer = num / 1;
	temp = num - (long long)num;
	while (temp - (long long)temp != 0)
		temp *= 10;
	decimal = (long long)temp;
	new = ft_strjoin(ft_itoa_base(integer, base), ".");
	ft_restrcat(&new, ft_itoa_base(decimal, base));
	return (new);
}
