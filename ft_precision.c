/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:34:29 by adaly             #+#    #+#             */
/*   Updated: 2017/06/04 03:36:01 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_integer(t_pfconv *current)
{
	long long	num_zeroes;
	char		*z_str;

	z_str = NULL;
	num_zeroes = current->precision - ft_strlen(current->string);
	if (num_zeroes > 0)
	{
		z_str = ft_strnew(num_zeroes);
		if (z_str)
		{
			ft_memset(z_str, '0', num_zeroes);
			ft_restrcat(&z_str, current->string);
			free(current->string);
			current->string = z_str;
		}
	}
}

void	ft_precision_string(t_pfconv *current)
{
	char 				*str;
	long long			length;

	str = NULL;
	length = 0;
	if (current)
	{
		str = current->string;
		if (str && current->precision >= 0)
		{
			length = ft_strlen(str);
			if (length > current->precision)
				str[current->precision] = 0;
		}
	}
}

void	ft_precision_float(t_pfconv *current, unsigned int precision)
{
	unsigned int		length;
	char				*ptr;
	char				*tail;

	tail = NULL;
	ptr = NULL;
	if (current)
	{
		if (current->string && current->precision >= 0)
		{
			if ((ptr = ft_strchr(current->string, '.')))
			{
				if (ft_lowercase(current->type) == 'g' && precision != 5 && precision > 0)
				{
					ptr = current->string;
					precision -= 1;
				}
				length = ft_strlen(ptr);
				if (length < precision)
				{
					ptr = ft_strnew((precision - length) + 1);
					if (ptr)
					{
						ft_memset(ptr, '0', (precision - length) + 1);
						ft_restrcat(&(current->string), ptr);
					}
				}
				else
				{
					ft_strclr(ptr + precision + 1);
				}
			}
		}
	}
}
