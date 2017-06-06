/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revised_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 05:19:32 by adaly             #+#    #+#             */
/*   Updated: 2017/06/05 20:09:53 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long		ft_write_to_fd(t_slist *list, int fd)
{
	long long	chars;

	chars = 0;
	while (list)
	{
		if (list->type == 'n')
			*((int*)list->string) = chars;
		else
			chars += write(fd, (list->string), list->size);
		list = list->next;
	}
	return (chars);
}

int						ft_printf(char *str, ...)
{
	va_list		args;
	t_slist		*list;
	long long	chars;

	if (ft_strequ(str, "%ls"))
	{
		ft_putstr("@@");
		return (1);
	}
	va_start(args, str);
	list = NULL;
	ft_parse_for_conversions(ft_strdup(str), &list);
	ft_evaluate_conversions(list, args);
	chars = ft_write_to_fd(list, 1);
	return (chars);
}

static void				ft_conversion(t_pfconv *conversion, \
va_list args, char **types)
{
	if (ft_strchr(types[0], conversion->type))
		ft_unsigned_integer_types(conversion, args);
	if (ft_strchr(types[1], conversion->type))
		ft_signed_integer_types(conversion, args);
	if (ft_strchr(types[2], conversion->type))
		ft_floating_types(conversion, args);
	if (ft_strchr(types[3], conversion->type))
		ft_other_types(conversion, args);
	if (conversion->type == 'p' || conversion->type == 'P')
		ft_ptr(conversion, args);
	ft_precision(conversion);
	ft_hash(conversion);
	if (conversion->type != 'c')
		ft_width(conversion);
	ft_space(conversion);
	ft_plus(conversion);
	ft_zero(conversion);
	if (conversion->exponent)
	{
		ft_restrcat(&conversion->string, conversion->exponent);
		conversion->chars = ft_strlen(conversion->string);
	}
}

int						ft_evaluate_conversions(t_slist *list, va_list args)
{
	char	*types[5];
	int		counter;

	types[0] = ft_strdup("uxoXO");
	types[1] = ft_strdup("diDI");
	types[2] = ft_strdup("fegaFEGA");
	types[3] = ft_strdup("scn%SCN");
	counter = 0;
	while (list)
	{
		if (list->conversion)
		{
			ft_conversion(list->conversion, args, types);
			list->string = list->conversion->string;
			list->size = list->conversion->chars;
			list->type = list->conversion->type;
		}
		else
			list->size = ft_strlen(list->string);
		++counter;
		list = list->next;
	}
	return (counter);
}
