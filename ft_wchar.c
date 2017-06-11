/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:38:23 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 17:09:09 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wchar_width(t_pfconv *current)
{
	uintmax_t	counter;
	uintmax_t	counter2;
	wchar_t		*wid;

	wid = NULL;
	counter = 0;
	counter2 = 0;
	if (current->width > 1)
	{
		counter = current->width - 1;
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

static void	ft_wchar_final(t_pfconv *current)
{
	uintmax_t	finalsize;
	wchar_t		*final;

	final = NULL;
	finalsize = ft_strlen(current->widthstr) + 1;
	final = ft_wstrnew(finalsize);
	if (final)
	{
		if (current->flags[0])
		{
			final[0] = ((wchar_t*)(current->val))[0];
			ft_wstrcpy(final + 1, ((wchar_t*)(current->widthstr)));
		}
		else if (widthstr)
		{
			ft_wstrcpy(final, ((wchar_t*)(current->widthstr)));
			final[finalsize - 1] = ((wchar_t*)(current->val))[0];
		}
		else
			final[0] = ((wchar_t*)(current->val))[0];
		current->chars = finalsize * sizeof(wchar_t);
		current->final = final;
	}
}

void		ft_wchar(t_pfconv *current, va_list args)
{
	if (current)
	{
		ft_import_options(current);
		current->valsize = sizeof(wchar_t);
		current->val = ft_memalloc(current->valsize);
		((wchar_t*)current->val)[0] = (wchar_t)va_arg(args, int);
		if (current->width > 1)
			ft_wchar_width(current);
		ft_wchar_final(current);
	}
}
