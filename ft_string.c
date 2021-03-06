/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 15:42:15 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 16:24:51 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_string_width(t_pfconv *current)
{
	if (current->width > current->chars)
	{
		current->widthstr = ft_strnew(current->width - current->chars);
		if (current->widthstr)
			ft_memset(current->widthstr, ' ', current->width - current->chars);
	}
}

static void	ft_string_precision(t_pfconv *current)
{
	if (current->precision < current->chars)
	{
		current->final[current->precision] = 0;
		current->chars = current->precision;
	}
}

static void	ft_string_final(t_pfconv *current)
{
	uintmax_t	where;

	where = 0;
	if (current->widthstr)
	{
		if (current->flags[0])
			where = ft_strlen(current->final);
		ft_restrinsert(&(current->final), current->widthstr, where);
	}
	current->chars = ft_strlen(current->final);
}

void		ft_string(t_pfconv *current, va_list args)
{
	void	*val;

	val = NULL;
	if (current)
	{
		ft_import_options(current);
		val = va_arg(args, char*);
		if (val)
		{
			current->final = ft_strdup(val);
			current->chars = ft_strlen(current->final);
			current->val = val;
			current->valsize = sizeof(void*);
			if (current->precision > 0)
				ft_string_precision(current);
			if (current->width > 0)
				ft_string_width(current);
			ft_string_final(current);
		}
		else
		{
			current->final = ft_strdup("(null)");
			current->chars = ft_strlen(current->final);
		}
	}
}
