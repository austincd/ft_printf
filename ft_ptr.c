/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:16:18 by adaly             #+#    #+#             */
/*   Updated: 2017/05/30 20:42:51 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptr(t_pfconv *current, va_list args)
{
	void	*ptr;
	char	*temp;

	ptr = NULL;
	temp = NULL;
	if (current && args)
	{
		ptr = va_arg(args, void*);
		if (current->width == -2)
			current->width = va_arg(args, int);
		if (current->precision == -2)
			current->precision = va_arg(args, int);
		temp = ft_utoa_base((unsigned long long)ptr, 16);
		if (temp)
			free(temp);
		current->string = ft_strjoin("0x", temp);
	}
	return (ft_strlen(current->string));
}
