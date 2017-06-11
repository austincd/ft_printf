/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:38:23 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 16:59:57 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_char_width(t_pfconv *current)
{
	uintmax_t	widsize;
	char		*wid;

	wid = NULL;
	widsize = current->width - 1;
	wid = ft_strnew(widsize);
	if (wid)
		ft_memset(wid, ' ', widsize);
	current->widthstr = wid;
}

static void	ft_char_final(t_pfconv *current)
{
	uintmax_t	finalsize;
	char		*final;

	final = NULL;
	finalsize = ft_strlen(current->widthstr) + 1;
	final = ft_strnew(finalsize);
	if (current->flags[0])
		where = 1;
	if (final)
	{
		if (current->flags[0])
		{
			final[0] = ((char*)(current->val))[0];
			ft_strcpy(final + 1, current->widthstr);
		}
		else if (widthstr)
		{
			ft_strcpy(final, current->widthstr);
			final[finalsize - 1] = ((char*)(current->val))[0];
		}
		else
			final[0] = ((char*)(current->val))[0];
		current->chars = finalsize;
		current->final = final;
	}
}

void		ft_char(t_pfconv *current, va_list args)
{
	if (current)
	{
		ft_import_options(current);
		current->valsize = sizeof(char);
		current->val = ft_memalloc(current->valsize);
		((char*)current->val)[0] = (char)va_arg(args, int);
		if (current->width > 1)
			ft_char_width(current);
		ft_char_final(current);
	}
}
