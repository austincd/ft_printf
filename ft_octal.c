/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 17:13:30 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 17:54:35 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_octal_width(t_pfconv *current)
{
	char		*width;
	uintmax_t	size;

	width = NULL;
	if (current->width > current->chars)
	{
		size = current->width - current->chars;
		width = ft_strnew(size);
		if (current->flags[3])
			ft_memset(width, '0', size);
		else
			ft_memset(width, ' ', size);
		current->widthstr = width;
	}
}

static void		ft_octal_precision(t_pfconv *current)
{
	char		*precistr;
	uintmax_t	size;

	precistr = NULL;
	if (current->precision > current->chars)
	{
		size = current->precision - current->chars;
		precistr = ft_strnew(size);
		ft_memset(precistr, '0', size);
	}
}

static void		ft_octal_mod(t_pfconv *current)
{
	ft_octal_width(current);
	ft_octal_precision(current);
	current->prefix = NULL;
	if (current->flags[4])
		current->prefix = ft_strdup("0");
}

static void		ft_octal_finalize(t_pfconv *current)
{
	char		*final;
	uintmax_t	where;

	where = 0;
	ft_restrcat(&final, current->prefix);
	ft_restrcat(&final, current->string);
	if (current->flags[3])
		where = ft_strlen(current->prefix);
	else if (current->flags[0])
		where = ft_strlen(final);
	ft_restrinsert(&final, current->widthstr, where);
	current->final = final;
	current->chars = ft_strlen(final);
}

void			ft_octal(t_pfconv *current, va_list args)
{
	uintmax_t	valsize;
	uintmax_t	*val;
	char		*str;

	valsize = sizeof(uintmax_t);
	val = (uintmax_t*)ft_memalloc(valsize);
	if (current)
	{
		ft_import_options(current, args);
		val[0] = va_arg(args, uintmax_t);
		if (current->length == 0)
			val[0] = (unsigned char)*val;
		if (current->length == 1)
			val[0] = (unsigned short)*val;
		if (current->length == 2)
			val[0] = (unsigned long)*val;
		str = ft_itoa_base(*val, 8);
		current->chars = ft_strlen(str);
		current->string = str;
		ft_octal_mod(current);
		ft_octal_finalize(current);
	}
}
