/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 06:51:40 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:05:26 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_internal(long long internal, char *new, char *buff)
{
	if (internal <= 9)
	{
		*buff = (char)internal + '0';
		ft_strncat(new, buff, 1);
	}
	if (internal > 9)
	{
		ft_itoa_internal((internal / 10), new, buff);
		ft_itoa_internal((internal % 10), new, buff);
	}
}

char		*ft_itoa(int n)
{
	long long	internal;
	int			length;
	char		*new;
	char		*buff;

	length = ft_numlen(n);
	buff = (char*)malloc(sizeof(char) * 1);
	new = ft_strnew((size_t)length);
	internal = (long long)n;
	if (buff && new)
	{
		if (internal < 0)
		{
			new[0] = '-';
			ft_itoa_internal((internal * -1), new, buff);
		}
		else
			ft_itoa_internal(internal, new, buff);
	}
	return (new);
}
