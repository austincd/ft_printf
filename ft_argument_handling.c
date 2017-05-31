/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:34:56 by adaly             #+#    #+#             */
/*   Updated: 2017/05/27 02:22:15 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

t_pfconv	*ft_new_pfconv(void)
{
	t_pfconv	*new;

	new = NULL;
	new = (t_pfconv*)ft_memalloc(sizeof(t_pfconv));
	if (new)
	{
		new->base = 10;
		new->length = 0;
		new->precision = -1;
		new->width = -1;
		new->capitalized = 0;
		new->type = 0;
		new->import_type = 0;
		new->conv_length = 0;
		new->parameter = 0;
		new->flags = NULL;
		new->string = NULL;
	}
	return (new);
}

char *ft_parse_parameter(char *str, t_pfconv *new)
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

char *ft_parse_flags(char *str, t_pfconv *new)
{
	char *ptr;
	char *flags;
	int		index;

	index = 0;
	flags = ft_strdup("-==0#");//"+ "
	ptr = str;
	if (new)
	{
		new->flags = (int*)ft_memalloc(sizeof(int) * 5);
		if (ptr && new->flags)
		{
			while (ft_strchr(flags, *ptr))
			{
				index = ft_strchr(flags, *ptr) - flags;
				if (new->flags[index] != 0)
				{
					//free(flags);
					return (NULL);
				}
				new->flags[index] = 1;
				++ptr;
			}
			return (ptr);
		}
	}
	return (str);
}

char	*ft_parse_width(char *str, t_pfconv *new)
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

char	*ft_parse_precision(char *str, t_pfconv *new)
{
	char	*ptr;

	ptr = str;
	if (new)
	{
		new->precision = -1;
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

char	*ft_parse_length(char *str, t_pfconv *new, char **options)
{
	char	*ptr;

	ptr = str;
	if (new)
	{
		new->length = -1;
		if (ptr)
		{
			new->length = ft_strequ_multi(ptr, options, 8);
			if (new->length >= 0)
				ptr += ft_strlen(options[new->length]);
		}
	}
	return (ptr);
}

char	*ft_parse_type(char *str, t_pfconv *new, char **types)
{
	char	*ptr;

	ptr = str;
	if (new && types)
	{
	new->type = 0;
		if (ptr)
		{
			while (!ft_strchr(types[0], *ptr))
				++ptr;
			if (ft_strchr(types[0], *ptr))
			{
				new->type = *ptr;
//				printf("type is %c\n", new->type); 
				if (new->type == 'a' || new->type == 'x')
					new->base = 16;
				if (new->type != *ptr)
					new->capitalized = 1;
				if (ft_strchr(types[1], new->type))
					new->import_type = 'i';
				else if (ft_strchr(types[2], new->type))
					new->import_type = '2';
				else if (ft_strchr(types[3], new->type))
					new->import_type = 'u';
				if (ft_strchr(types[5], *ptr))
					new->length = 2;
				return (ptr + 1);
			}
		}
	}
	return (NULL);
}

char	**ft_build_types(void)
{
	char **types;
	int	index;

	index = 6;
	types = (char**)ft_memalloc(sizeof(char*) * index);
	types[0] = ft_strdup("sSpPdDiIoOuUxXcCeEfFgGaAn%");
	types[1] = ft_strdup("di");
	types[2] = ft_strdup("fega");
	types[3] = ft_strdup("uxo");
	types[4] = ft_strdup("scpn%");
	types[5] = ft_strdup("DOU");
	return (types);
}

char	**ft_build_lengths(void)
{
	char **lengths;

	lengths = (char**)ft_memalloc(sizeof(char*) * 8);
	lengths[0] = ft_strdup("hh");
	lengths[1] = ft_strdup("h");
	lengths[2] = ft_strdup("l");
	lengths[3] = ft_strdup("ll");
	lengths[4] = ft_strdup("L");
	lengths[5] = ft_strdup("z");
	lengths[6] = ft_strdup("j");
	lengths[7] = ft_strdup("t");
	return (lengths);
}
