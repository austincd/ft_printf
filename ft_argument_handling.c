/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:34:56 by adaly             #+#    #+#             */
/*   Updated: 2017/06/05 19:20:28 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pfconv	*ft_conversion_parsing(char **str)
{
	t_pfconv	*new;
	char		*temp;

	new = ft_new_pfconv();
	if (str)
	{
		if (**str == '%')
		{
			temp = *str;
			*str = *str + 1;
			*str = ft_parse_parameter(*str, new);
			*str = ft_parse_flags(*str, new);
			*str = ft_parse_width(*str, new);
			*str = ft_parse_precision(*str, new);
			*str = ft_parse_length(*str, new, ft_build_lengths());
			*str = ft_parse_type(*str, new, ft_build_types());
			if (new->type == 'o')
				new->base = 8;
			new->conv_length = *str - temp;
			new->orig = ft_strnew(new->conv_length);
			ft_strncpy(new->orig, temp, new->conv_length);
		}
	}
	return (new);
}

char		*ft_parse_parameter(char *str, t_pfconv *new)
{
	char *ptr;

	ptr = str;
	if (new)
		new->parameter = -1;
	if (ptr)
	{
		while (ft_isdigit(*ptr))
			++ptr;
		if (*ptr == '$')
		{
			new->parameter = ft_atoi(str);
			return (ptr + 1);
		}
	}
	return (str);
}

char		*ft_parse_flags(char *str, t_pfconv *new)
{
	char	*ptr;
	char	*flags;
	int		index;

	index = 0;
	flags = ft_strdup("-+ 0#");
	ptr = str;
	if (new)
	{
		new->flags = (int*)ft_memalloc(sizeof(int) * 5);
		if (ptr && new->flags)
		{
			while (ft_strchr(flags, *ptr))
			{
				index = ft_strchr(flags, *ptr) - flags;
				new->flags[index] = 1;
				++ptr;
			}
			return (ptr);
		}
	}
	return (str);
}

char		*ft_parse_width(char *str, t_pfconv *new)
{
	char	*ptr;

	ptr = str;
	if (new)
	{
		new->width = 0;
		if (ptr)
		{
			if (*ptr == '*')
			{
				new->width = -2;
				return (ptr + 1);
			}
			else if (ft_isdigit(*ptr))
			{
				new->width = ft_atoi(ptr);
				while (ft_isdigit(*ptr))
					++ptr;
				return (ptr);
			}
			else
				return (ptr);
		}
	}
	return (ptr);
}

char		*ft_parse_precision(char *str, t_pfconv *new)
{
	char	*ptr;

	ptr = str;
	if (new)
	{
		if (ptr)
		{
			if (*ptr == '.')
			{
				++ptr;
				if (ft_isdigit(*ptr))
				{
					new->precision = ft_atoi(ptr);
					while (ft_isdigit(*ptr))
						++ptr;
				}
				else if (*ptr == '*')
				{
					new->precision = -2;
					++ptr;
				}
			}
		}
	}
	return (ptr);
}
