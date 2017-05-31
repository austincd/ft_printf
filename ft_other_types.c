/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 20:12:55 by adaly             #+#    #+#             */
/*   Updated: 2017/05/30 20:45:47 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_char(t_pfconv *current, char c)
{
	current->string = ft_strnew(1);
	current->string[0] = c;
	current->chars = 1;
	return (1);
}

static int	ft_char_wide(t_pfconv *current, unsigned int c)
{
	int				width;
	unsigned long	full_char;

	full_char = ft_char_expand(c);
	width = ft_utf8width((unsigned char*)&full_char);
	current->string = ft_strnew(width);
	current->chars = width;
	ft_memcpy(current->string, &full_char, width);
	return (width);
}

static int	ft_string(t_pfconv *current, char *c)
{
//	printf("str is %s\n", c);
	current->string = ft_strdup(c);
	current->chars = ft_strlen(current->string);
//	printf("current string is %s, chars is %d", current->string, current->chars);
	return (current->chars);
}

static int	ft_string_wide(t_pfconv *current, char *c)
{
	wchar_t	*wc;
//	int		size;
	int		index;

	index = 0;
	wc = (wchar_t*)c;
	while (wc[index])
		++index;
//	printf("index is %d\n", index);
	current->string = (char*)ft_memalloc(sizeof(wchar_t) * (index + 1));
//	current->string = ft_strdup(c);
	current->chars = index * sizeof(wchar_t);
	ft_memcpy(current->string, wc, current->chars);
//	printf("str is %ls\n", (wchar_t*)current->string);
//	printf("%i\n", current->chars);
	return (current->chars);
}

int		ft_other_types(t_pfconv *current, va_list args)
{
//	printf("type %c\n", current->type);
	if (ft_lowercase(current->type) == 'c')
		ft_char(current, va_arg(args, int));
	else if (current->type == 'C')
		ft_char_wide(current, va_arg(args, int));
	if (current->type == 's')
		ft_string(current, va_arg(args, char*));
	if (current->type == 'S' || (current->type == 's' && current->length == 2))
		ft_string_wide(current, va_arg(args, char*));
	if (current->type == '%')
		ft_char(current, '%');
	return (current->chars);
}
