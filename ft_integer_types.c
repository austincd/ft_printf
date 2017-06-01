/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:56:52 by adaly             #+#    #+#             */
/*   Updated: 2017/05/31 15:13:20 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_signed_integer_types(t_pfconv *current, va_list args)
{
	long long	new;
	char		*str;
	int			base;

	if (current->width == -2)
		current->width = va_arg(args, unsigned int);
	if (current->precision == -2)
		current->precision = va_arg(args, unsigned int);
	base = 10;
	if (current->type == 'x' || current->type == 'X')
		base = 16;
	if (current->type == 'o' || current->type == 'O')
		base = 8;
	new = 0;
	if (current->length >= -1 && current->length <= 1)
		new = va_arg(args, int);
	if (current->length == 2)
		new = va_arg(args, long int);
	if (current->length == 3)
		new = va_arg(args, long long int);
	str = ft_itoa_base(new, base);
	current->string = str;
	current->chars = ft_strlen(str);
	return (ft_strlen(str));
}

int	ft_unsigned_integer_types(t_pfconv *current, va_list args)
{
	unsigned long long	new;
	char		*str;
	int			base;

	if (current->width == -2)
		current->width = va_arg(args, unsigned int);
	if (current->precision == -2)
		current->precision = va_arg(args, unsigned int);
	base = 10;
	if (current->type == 'x' || current->type == 'X')
		base = 16;
	if (current->type == 'o' || current->type == 'O')
		base = 8;
	new = 0;
	if (current->length >= -1 && current->length <= 1)
		new = va_arg(args, unsigned int);
	if (current->length == 2)
		new = va_arg(args, unsigned long int);
	if (current->length >= 3 && current->length <= 7 && current->length != 4)
		new = va_arg(args, unsigned long long);
	str = ft_utoa_base(new, base);
	if (ft_tolower(current->type) == current->type)
		current->string = ft_strlowcase(str);
	current->chars = ft_strlen(str);
	return (current->chars);
}
