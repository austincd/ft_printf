/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_types.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:21:01 by adaly             #+#    #+#             */
/*   Updated: 2017/06/02 16:36:46 by adaly            ###   ########.fr       */
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
	div = num;
	while (div >= 2)
		div = num / ft_power(++counter, 2);
	str = ft_strdup("0X");
	last = ft_basefloat(div, 16);
	ft_restrcat(&str, last);
	ft_restrcat(&str, "P");
	last = ft_itoa_base(counter, 10);
	ft_restrcat(&str, last);
	if (current->type == 'a')
		ft_strlowcase(str);
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
	if (current->precision <= 0)
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
