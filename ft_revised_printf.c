/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revised_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 05:19:32 by adaly             #+#    #+#             */
/*   Updated: 2017/05/30 15:28:09 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *str, ...)
{
	long long	chars;
	va_list		args;
	t_slist		*list;

	chars = 0;
	int counter = 0;
	va_start(args, str);
	list = NULL;
	ft_parse_for_conversions(ft_strdup(str), &list);
	ft_evaluate_conversions(list, args);
	while (list)
	{
		if (list->string)
			ft_putstr(list->string);//printf("%s\n", list->string);
		//chars += write(1, (list->string), list->size);
//		printf("list entry %d\n%p\n%s\n%llu\n", counter, list, list->string, list->size);
		++counter;
		list = list->next;
	}
	return (chars);
}

int				ft_evaluate_conversions(t_slist *list, va_list args)
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
			if (ft_strchr(types[0], list->conversion->type))
				 ft_unsigned_integer_types(list->conversion, args);
			if (ft_strchr(types[1], list->conversion->type))
				 ft_signed_integer_types(list->conversion, args);
			if (ft_strchr(types[2], list->conversion->type))
				 ft_floating_types(list->conversion, args);
			if (ft_strchr(types[3], list->conversion->type))
				 ft_other_types(list->conversion, args);
		}
	}
}

/*int			ft_evaluate_conversions(t_slist *list, va_list args)
{
	char	*types[3];
	int		counter;

	counter = 0;
	types[0] = ft_strdup("ilmzjtuvw");
	types[1] = ft_strdup("LDf2");
	types[2] = ft_strdup("cs%p");
	while (list)
	{
		if (list->conversion)
		{
				ft_import_type(list->conversion);
			if (ft_strchr(types[0], list->conversion->import_type))
				ft_printf_int(list->conversion, args);
			else if (ft_strchr(types[1], list->conversion->import_type))
				ft_printf_double(list->conversion, args);
			if (ft_strchr(types[2], list->conversion->type))
				ft_printf_other(list->conversion, args);
			ft_width(list->conversion);
			list->string = list->conversion->string;
			list->conversion->chars = ft_strlen(list->string);
			list->size = list->conversion->chars;
		}
		list = list->next;
		++counter;
	}
	return (counter);
}*/

