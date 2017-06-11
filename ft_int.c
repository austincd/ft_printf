/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 18:09:06 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 18:15:37 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_int_width(t_pfconv *current)
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

static void		ft_int_precision(t_pfconv *current)
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

static void		ft_int_mod(t_pfconv *current)
{
	ft_uint_width(current);
	ft_uint_precision(current);
	current->prefix = NULL;
	if (current->flags[4])
		current->prefix = ft_strdup("0");
}

static void		ft_int_finalize(t_pfconv *current)
{
	char		*final;
	uintmax_t	where;

	where = 0;
	ft_restrcat(&final, current->prefix);
	ft_restrcat(&final, current->precistr);
	ft_restrcat(&final, current->string);
	if (current->flags[3])
		where = ft_strlen(current->prefix);
	if (current->flags[0])
		where = ft_strlen(final);
	ft_restrinsert(&final, current->widthstr, where);
	current->final = final;
	current->chars = ft_strlen(final);
}

void			ft_int(t_pfconv *current, va_list args)
{
	uintmax_t	valsize;
	intmax_t	*val;
	char		*str;

	valsize = sizeof(uintmax_t);
	val = (intmax_t*)ft_memalloc(valsize);
	if (current)
	{
		ft_import_options(current, args);
		val[0] = va_arg(args, intmax_t);
		if (current->length == 0)
			val[0] = (char)*val;
		if (current->length == 1)
			val[0] = (short)*val;
		if (current->length == 2)
			val[0] = (long)*val;
		if (val[0] < 0)
		{
			val[0] *= -1;
			current->prefix = ft_strdup("-");
		}
		str = ft_itoa_base(*val, 10);
		current->chars = ft_strlen(str);
		current->string = str;
		ft_int_mod(current);
		ft_int_finalize(current);
	}
}
