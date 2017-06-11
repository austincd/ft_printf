/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:56:52 by adaly             #+#    #+#             */
/*   Updated: 2017/06/09 21:57:19 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_signed_integer_types(t_pfconv *current, va_list args)
{
	intmax_t	new;
	char		*str;
	int			base;

	ft_import_options(current, args);
	base = 10;
	if (current->type == 'x' || current->type == 'X')
		base = 16;
	if (current->type == 'o' || current->type == 'O')
		base = 8;
	new = 0;
	if (current->length >= -1 && current->length <= 1)
		new = va_arg(args, int);
	if (current->length == 0)
		new = (char)new;
	if (current->length == 1)
		new = (short)new;
	if (current->length == 2)
		new = va_arg(args, long int);
	if (current->length >= 3)
		new = va_arg(args, intmax_t);
	str = ft_itoa_base(new, base);
	current->string = str;
	current->chars = ft_strlen(str);
}

void	ft_unsigned_integer_types(t_pfconv *current, va_list args)
{
	uintmax_t			new;
	char				*str;
	int					base;

	ft_import_options(current, args);
	base = 10;
	if (current->type == 'x' || current->type == 'X')
		base = 16;
	if (current->type == 'o' || current->type == 'O')
		base = 8;
	if (current->length >= -1 && current->length <= 1 && current->type != 'U')
		new = va_arg(args, unsigned int);
	if (current->length == 0)
		new = (unsigned char)new;
	if (current->length == 1)
		new = (unsigned short)new;
	if (current->length == 2 || current->type == 'U')
		new = va_arg(args, unsigned long int);
	if ((current->length >= 3 && current->length <= 7 && current->length != 4))
		new = va_arg(args, uintmax_t);
	str = ft_ntoa(new, base, 0);
	if (ft_tolower(current->type) == current->type)
		current->string = ft_strlowcase(str);
	else
		current->string = str;
	current->chars = ft_strlen(str);
}
