/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:34:42 by adaly             #+#    #+#             */
/*   Updated: 2017/06/06 17:49:44 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision(t_pfconv *current)
{
	char	*strs;
	char	*ints;
	char	*floats;

	ints = ft_strdup("xXuUiIoOdD");
	strs = ft_strdup("sS");
	floats = ft_strdup("gGfFaAeE");
	if (current)
	{
//		if (current->flags[3] && current->precision >= 0)
//			ft_zero(current);
		if (ft_strchr(ints, current->type))
			ft_precision_integer(current);
		else if (ft_strchr(strs, current->type))
			ft_precision_string(current);
		else if (ft_strchr(floats, current->type))
			ft_precision_float(current, current->precision);
		if (ft_strchr(ints, current->type) || \
		ft_strchr(strs, current->type) || ft_strchr(floats, current->type))
			current->chars = ft_strlen(current->string);
	}
	free(ints);
	free(strs);
	free(floats);
}

/*static void	ft_width_helper(t_pfconv *current, unsigned int diff, char *tmp)
{
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
}

void		ft_width(t_pfconv *current)
{
	char			*tmp;
	unsigned int	diff;

	diff = current->width - current->chars;
	if (current)
	{
		if (current->string && current->width >= 0)
		{
			if (current->chars < current->width)
			{
				tmp = ft_strnew(current->width);
				ft_width_helper(current, diff, tmp);
				free(current->string);
				current->string = tmp;
				current->chars = ft_strlen(current->string);
			}
		}
	}
}
*/
