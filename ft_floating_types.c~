/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_types.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:21:01 by adaly             #+#    #+#             */
/*   Updated: 2017/06/02 17:45:36 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_g(t_pfconv *current, long double num)
{
	char *temp1;
	char *temp2;

	temp1 = ft_float_standard(current, num, 10);
	temp2 = ft_float_standard(current, num, 10);
	if (ft_strlen(temp2) < ft_strlen(temp1))
	{
		current->string = temp2;
		free(temp1);
	}
	else
	{
		current->string = temp1;
		free(temp2);
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
	if (counter >= 0)
		ft_restrcat(&current->exponent, "+");
	if (div == 0)
		counter = 0;
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
	if (current->precision <= 0 && ft_lowercase(current->type) == 'f')
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
		current->string = ft_float_standard(current, new, base);
	else if (ft_lowercase(current->type) == 'f')
		current->string = ft_float_normal(current, new, base);
	else if (ft_lowercase(current->type) == 'a')
		ft_a(current, new);
	current->chars = ft_strlen(current->string);
	return (ft_strlen(current->string));
}
