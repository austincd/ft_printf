/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 04:18:19 by adaly             #+#    #+#             */
/*   Updated: 2017/05/27 02:23:19 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_eval_num(t_pfconv *current, long long num)
{
	char	*str;
	char	*temp;
	int		length;

//	printf("num is %lld\n", num);
	length = 0;
	str = NULL;
	if (current)
	{
		if (current->flags[1] && num >= 0)
			str = ft_strdup ("+");
		else if (current->flags[2])
			str = ft_strdup (" ");
		ft_restrcat(&str, ft_itoa_base(num, current->base));
		current->string = str;
		if (str)
			length = ft_strlen(str);
		if (current->width >= length)
		{
			temp = ft_strnew(length - current->width);
			ft_memset(temp, ' ', length - current->width);
			if (current->flags[3])
				ft_memset(temp, '0', length - current->width);
			ft_restrcat(&temp, str);
			current->string = temp;
			//free(str);
		}
	}
}

void		ft_eval_unum(t_pfconv *current, unsigned long long num)
{
	char	*str;
	char	*temp;
	int		length;

	str = NULL;
	if (current)
	{
		if (current->flags[1])
			str = ft_strdup ("+");
		else if (current->flags[2])
			str = ft_strdup (" ");
		ft_restrcat(&str, ft_utoa_base(num, current->base));
		current->string = str;
		length = ft_strlen(str);
		if (current->width >= length)
		{
			temp = ft_strnew(length - current->width);
			ft_memset(temp, ' ', length - current->width);
			if (current->flags[3])
				ft_memset(temp, '0', length - current->width);
			ft_restrcat(&temp, str);
			current->string = temp;
			//free(str);
		}
	}
}

void		ft_eval_str(t_pfconv *current, char *str)
{
	long long	length;
	char		*new;

	length = ft_strlen(str);
	if (current)
	{
		if (length > current->precision && current->precision >= 0)
			length = current->precision;
		new = ft_strnew(length);
		ft_strlcpy(new, str, length + 1);
		current->string = new;
	}
}
void		ft_eval_char(t_pfconv *current, char c)
{
	if (current)
	{
		current->string = ft_strnew(1);
		current->string[0] = c;
	}
}

void		ft_eval_float(t_pfconv *current, long double num)
{
	char	*temp1;
	char	*temp2;

	if (current)
	{
		if (current->type == 'g')
		{
			temp1 = ft_float_standard(current, num, 10);
			temp2 = ft_float_normal(current, num, 10);
			if (ft_strlen(temp1) < ft_strlen(temp2))
				current->string = temp1;
			else
				current->string = temp2;
		}
		else if (current->type == 'e')
			current->string = ft_float_standard(current, num, 10);
		else if (current->type == 'f')
			current->string = ft_float_normal(current, num, 10);
		else if (current->type == 'a')
			current->string = ft_float_normal(current, num, 16);
		ft_precision(current, current->precision);
/*		if (ft_strlen(ft_strchr(current->string, '.')) - 1 < current->precision)
		{
			length = ft_strlen(ft_strchr(current->string, '.')) - 1;
		}
		else
			*(ft_strchr(current->string, '.') + current->precision + 1) = 0;*/
	}
}
