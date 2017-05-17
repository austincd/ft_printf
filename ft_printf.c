/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 06:37:13 by adaly             #+#    #+#             */
/*   Updated: 2017/05/17 05:47:24 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf(char *str, ...)
{
	t_pfconv			**conversions;
	va_list				args;
	char				*ints;
	int					index;
	unsigned long long	chars;

	va_start(args, str);
	conversions = ft_parse_for_conversions(str);
	index = 0;
	chars = ft_strlen(str);
	ints = ft_strdup("ilmzjtuvw");
	while (conversions[index])
	{
		ft_import_type(conversions[index]);
		if (ft_strchr(ints, conversions[index]->import_type))
			ft_printf_int(str, conversions[index], args);
		else if (conversions[index]->import_type == 'L' ||
				conversions[index]->import_type == 'D')
			ft_printf_double(str, conversions[index], args);
		else
			ft_printf_other(str, conversions[index], args);
		chars += (ft_strlen(conversions[index]->string) - conversions[index]->conv_length);
		ft_find_replace(&str, conversions[index]->orig, conversions[index]->string);
		++index;
	}
	write(1, str, chars);
}

void		ft_printf_int(char *str, t_pfconv *current, va_list args)
{
	if (current)
	{
		if (current->width == -2)
			current->width = va_arg(args, int);
		if (current->precision == -2)
			current->precision = va_arg(args, int);
		if (current->import_type == 'i')
			ft_eval_num(current, va_arg(args, int));
		if (current->import_type == 'l')
			ft_eval_num(current, va_arg(args, long int));
		if (current->import_type == 'm')
			ft_eval_num(current, va_arg(args, long long int));
		if (current->import_type == 'u')
			ft_eval_unum(current, va_arg(args, unsigned int));
		if (current->import_type == 'v')
			ft_eval_unum(current, va_arg(args, unsigned long int));
		if (current->import_type == 'w')
			ft_eval_unum(current, va_arg(args, unsigned long long int));
	}
}

void		ft_printf_double(char *str, t_pfconv *current, va_list args)
{
	if (current)
	{
		if (current->width == -2)
			current->width = va_arg(args, int);
		if (current->precision == -2)
			current->precision = va_arg(args, int);
		if (current->import_type == 'L')
			ft_eval_float(current, va_arg(args, long double));
		if (current->import_type == 'D')
			ft_eval_float(current, va_arg(args, double));
	}
}
void		ft_printf_other(char *str, t_pfconv *current, va_list args)
{
		if (current->width == -2)
			current->width = va_arg(args, int);
		if (current->precision == -2)
			current->precision = va_arg(args, int);
		if (current->import_type == 's')
			ft_eval_str(current, va_arg(args, char*));
		if (current->import_type == 'c')
			ft_eval_char(current, va_arg(args, char));
}

t_pfconv	**ft_parse_for_conversions(char *str)
{
	t_pfconv	**conversions;
	int			num_of_convs;
	int			index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '%')
			++num_of_convs;
		++index;
	}
	conversions = (t_pfconv**)ft_memalloc(sizeof(t_pfconv*) * num_of_convs + 1);
	index = 0;
	while (*str)
	{
		if (*str == '%')
		{
			conversions[index] = ft_conversion_parsing(&str);
			++index;
		}
		++str;
		
	}
	conversions[index] = NULL;
	return (conversions);
}
