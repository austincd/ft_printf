/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_types.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:21:01 by adaly             #+#    #+#             */
/*   Updated: 2017/06/04 03:01:52 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_e(t_pfconv *current, long double num)
{
	int		counter;
	int		sign;
	char	*str;
	char	*exponent;
	char	*last;

	sign = 0;
	counter = 0;
	str = NULL;
	exponent = NULL;
	if (num < 0)
	{
		num *= -1;
		sign = -1;
	}
	while (num >= 10)
	{
		num /= 10;
		++counter;
	}
	if (sign == -1)
	{
		str = ft_strdup("-");
		ft_restrcat(&str, ft_ftoa(num));
	}
	else
		str = ft_ftoa(num);
	exponent = ft_strdup("E+");
	last = ft_itoa(counter);
	if (counter < 10)
		ft_restrcat(&exponent, "0");
	ft_restrcat(&exponent, last);
	current->string = str;
	current->exponent = exponent;
	if (last)
		free(last);
	if (current->type == 'e')
	{
		ft_strlowcase(str);
		ft_strlowcase(current->exponent);
	}
}

static void		ft_g(t_pfconv *current, long double num)
{
	long long	length1;
	long long	length2;
	char		*temp;
	char		*temp2;

	ft_e(current, num);
	length1 = ft_strlen(current->string);
	temp = ft_float_normal(current, num, 10);
	temp2 = ft_strstr(temp, "00000");
	if (temp2)
		*temp2 = 0;
		length2 = ft_strlen(temp);
//	printf("normal is %s\n", temp);
//	printf("standard is %s%s\n", current->string, current->exponent);
	if (length1 < length2 + 4)
		free(temp);
	else
	{
		free(current->string);
		current->string = temp;
		free(current->exponent);
		current->exponent = NULL;
	}
}

static void		ft_a(t_pfconv *current, long double num)
{
	int		counter;
	char	*str;
	char	*last;
	long double div;

	str = NULL;
	counter = -7;
	if (num < 0)
	{
		num *= -1;
		str = ft_strdup("-0X");
	}
	else if (num == 0)
		str = ft_strdup("0X0");
	else
		str = ft_strdup("0X");
	div = num;
	while (div >= 2)
		div = num / ft_power(++counter, 2);
	last = ft_basefloat(div, 16);
	ft_restrcat(&str, last);
	free(last);
	current->exponent = ft_strdup("P");
	if (div == 0)
		counter = 0;
	if (counter >= 0)
		ft_restrcat(&current->exponent, "+");
	last = ft_itoa_base(counter, 10);
	ft_restrcat(&current->exponent, last);
	free(last);
	if (current->type == 'a')
	{
		ft_strlowcase(str);
		ft_strlowcase(current->exponent);
	}
	current->string = str;
}

int	ft_floating_types(t_pfconv *current, va_list args)
{
	long double	new;
	int			base;

	base = 10;
	new = 0;
	if (current->width == -2)
		current->width = va_arg(args, int);
	if (current->precision == -2)
		current->precision = va_arg(args, int);
	if (current->precision <= 0 && ft_lowercase(current->type) != 'a')
		current->precision = 6;
	if (ft_lowercase(current->type) == 'a')
		base = 16;
	if (current->length == 4)
		new = va_arg(args, double);
	else
		new = va_arg(args, double);
	if (ft_lowercase(current->type) == 'g')
		ft_g(current, new);
	else if (ft_lowercase(current->type) == 'e')
		ft_e(current, new);
	else if (ft_lowercase(current->type) == 'f')
		current->string = ft_float_normal(current, new, base);
	else if (ft_lowercase(current->type) == 'a')
		ft_a(current, new);
	current->chars = ft_strlen(current->string);
	return (ft_strlen(current->string));
}
