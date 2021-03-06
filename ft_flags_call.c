/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_call.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:56:14 by adaly             #+#    #+#             */
/*   Updated: 2017/06/09 22:28:47 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_flags_integer(t_pfconv *current)
{
//	printf("prefixwidthstring = %s%s%s\n", current->prefix, current->widthstr, current->string);
	ft_hash(current);
//	printf("prefixwidthstring = %s%s%s\n", current->prefix, current->widthstr, current->string);
	ft_zero(current);
//	printf("prefixwidthstring = %s%s%s\n", current->prefix, current->widthstr, current->string);
	ft_space(current);
//	printf("prefixwidthstring = %s%s%s\n", current->prefix, current->widthstr, current->string);
	ft_plus(current);
//	printf("prefixwidthstring = %s%s%s\n", current->prefix, current->widthstr, current->string);
	ft_minus(current);
//	printf("prefixwidthstring = %s%s%s\n", current->prefix, current->widthstr, current->string);
}

static void ft_flags_float(t_pfconv *current)
{
	ft_hash(current);
	ft_space(current);
	ft_plus(current);
	ft_zero(current);
	ft_minus(current);
}

static void ft_flags_other(t_pfconv *current)
{
	ft_hash(current);
	ft_space(current);
	ft_plus(current);
	ft_zero(current);
	ft_minus(current);
}

void		ft_flags(t_pfconv *current)
{
	char	**types;

	types = ft_build_types_alt();
	if (current)
	{
		if (ft_strchr(types[0], current->type))
			ft_flags_integer(current);
		else if (ft_strchr(types[1], current->type))
			ft_flags_float(current);
		else if (ft_strchr(types[2], current->type))
			ft_flags_other(current);
	}
	ft_strdel_plus(types + 0);
	ft_strdel_plus(types + 1);
	ft_strdel_plus(types + 2);
	free(types);
}
