/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 06:37:13 by adaly             #+#    #+#             */
/*   Updated: 2017/05/27 06:48:55 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int		ft_printf(char *str, ...)
{
	t_pfconv			**conversions;
	va_list				args;
	char				*types[3];
	int					index;
	unsigned long long	chars;
	char				*new;
	int					after;

	printf("::\n%s\n:\n", str);
	after = 0;
	va_start(args, str);
	new = NULL;
	new = ft_strdup(str);
	conversions = ft_parse_for_conversions(new);
	index = 0;
	chars = ft_strlen(new);
	types[0] = ft_strdup("ilmzjtuvw");
	types[1] = ft_strdup("LDf2");
	types[2] = ft_strdup("cs%p");
	while (conversions[index])
	{
//		printf("width %d, precision %d", conversions[index]->width, conversions[index]->precision);
//		printf("type %c\norig %s\n", conversions[index]->type, conversions[index]->orig);
		ft_import_type(conversions[index]);
//		printf("type %c\n import_type %c\n", conversions[index]->type, conversions[index]->import_type);
		if (ft_strchr(types[0], conversions[index]->import_type))
			ft_printf_int(conversions[index], args);
		else if (ft_strchr(types[1], conversions[index]->import_type))
			ft_printf_double(conversions[index], args);
		if (ft_strchr(types[2], conversions[index]->type))
		{
			ft_printf_other(conversions[index], args);
		}
		conversions[index]->chars = ft_strlen(conversions[index]->string);
		ft_width(conversions[index]);
		printf("string is : %s\n", conversions[index]->string);
		chars += (ft_strlen(conversions[index]->string) - conversions[index]->conv_length);
		after += ft_find_replace_after(&new, conversions[index]->orig, conversions[index]->string, after);
		++index;
	}
	write(1, new, chars);
	free(new);
	return (chars);
}*/

void		ft_printf_int(t_pfconv *current, va_list args)
{
	char	*new;

	new = ft_strdup("wzjt");
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
		if (ft_strchr(new, current->import_type))
			ft_eval_unum(current, va_arg(args, unsigned long long));
	}
	free(new);
}

void		ft_printf_double(t_pfconv *current, va_list args)
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
		if (current->import_type == '2')
			ft_eval_float(current, va_arg(args, double));
	}
}
void		ft_printf_other(t_pfconv *current, va_list args)
{
		if (current->width == -2)
			current->width = va_arg(args, int);
		if (current->precision == -2)
			current->precision = va_arg(args, int);
		if (current->import_type == 's')
			ft_eval_str(current, va_arg(args, char*));
		if (current->type == 'c')
			ft_eval_char(current, va_arg(args, unsigned int));
		if	(current->type == '%')
			ft_eval_char(current, '%');
}

void	ft_parse_for_conversions(char *str, t_slist **first)
{
	t_slist		*entry;

	entry = NULL;
	while (str)
	{
		entry = ft_new_tslist(entry, NULL, 0);
//		printf("%s\n", str);
		if (!*first)
			*first = entry;
		if (*str == '%')
		{
			entry->conversion = ft_conversion_parsing(&str);
			++str;
		}
		else
		{
			entry->string = ft_strtcdup(str, '%');
//			printf("entry string is %s\n", entry->string);
			str = ft_strchr(str, '%');
		}
	}
	free(str);
}
