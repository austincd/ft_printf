/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:34:42 by adaly             #+#    #+#             */
/*   Updated: 2017/06/01 13:44:45 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision(t_pfconv *current)
{
	char *strs;
	char *floats;

	strs = ft_strdup("sS");
	floats = ft_strdup("gGfFaAeE");
	if (current)
	{
		if (ft_strchr(strs, current->type))
		{
			ft_precision_string(current);
			current->chars = ft_strlen(current->string);
		}
		else if (ft_strchr(floats, current->type))
		{
			ft_precision_float(current, current->precision);
			current->chars = ft_strlen(current->string);
		}
	}
	free(strs);
	free(floats);
}

void	ft_width(t_pfconv *current)
{
	char			*tmp;
//  char			*new;
	unsigned int	diff;

	diff = current->width - current->chars;
	tmp = NULL;
//  new = NULL;
	if (current)
	{
		if (current->string && current->width >= 0)
		{
			if (current->chars < current->width)
			{
				tmp = ft_strnew(current->width);
				if (current->flags[0] == 1)
				{
					ft_memcpy(tmp, current->string, current->chars);
					ft_memset(tmp + current->chars, ' ', diff);
				}
				else
				{
					ft_memset(tmp, ' ', diff);
					ft_memcpy(tmp + diff, current->string, current->chars);
				}
				free(current->string);
				current->string = tmp;
				current->chars = ft_strlen(current->string);
			}
		}
	}
}
