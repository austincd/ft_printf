/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 15:42:15 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 16:37:51 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wstring_width(t_pfconv *current)
{
	uintmax_t	counter;
	uintmax_t	counter2;
	wchar_t		*wid;

	wid = NULL;
	counter = 0;
	counter2 = 0;
	if (current->width > current->wchars)
	{
		counter = current->width - current->wchars;
		wid = ft_wstrnew(counter);
		if (wid)
		{
			while (counter2 < counter)
			{
				wid[counter2] = ' ';
				++counter2;
			}
			current->widthstr = (char*)wid;
		}
	}
}

static void	ft_wstring_precision(t_pfconv *current)
{
	if (current->precision < current->chars)
	{
		((wchar_t*)current->final)[current->precision] = 0;
		current->wchars = current->precision;
	}
}

static void	ft_wstring_final(t_pfconv *current)
{
	uintmax_t	where;

	where = 0;
	if (current->widthstr)
	{
		if (current->flags[0])
			where = ft_wstrlen((wchar_t*)current->final);
		ft_wrestrinsert((wchar_t**)&(current->final), \
		(wchar_t*)current->widthstr, where);
	}
	current->chars = ft_wstrlen((wchar_t*)current->final) * sizeof(wchar_t);
}

void		ft_wstring(t_pfconv *current, va_list args)
{
	void	*val;

	val = NULL;
	if (current)
	{
		ft_import_options(current);
		val = va_arg(args, wchar_t*);
		if (val)
		{
			current->final = ft_wstrdup(val);
			current->wchars = ft_wstrlen((wchar_t*)current->final);
			current->val = val;
			current->valsize = sizeof(void*);
			if (current->precision > 0)
				ft_wstring_precision(current);
			if (current->width > 0)
				ft_wstring_width(current);
			ft_wstring_final(current);
		}
		else
		{
			current->final = (char*)ft_wstrdup("(null)");
			current->wchars = ft_wstrlen((wchar_t*)(current->final));
		}
	}
}
