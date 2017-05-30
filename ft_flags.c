/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 21:34:57 by adaly             #+#    #+#             */
/*   Updated: 2017/05/26 22:13:06 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(t_pfconv *current)
{
	char			*tmp;
//	char			*new;
	unsigned int	diff;

	diff = current->width - current->chars;
	tmp = NULL;
//	new = NULL;
	if (current)
	{
		if (current->string && current->width >= 0)
		{
			if (current->chars < current->width)
			{
				tmp = ft_strnew(current->width);
				if (current->flags[0] == 1)
				{
					ft_memcpy(tmp, current->string, current->chars);
					ft_memset(tmp + current->chars, ' ', diff);
				}
				else
				{
					ft_memset(tmp, ' ', diff);
					ft_memcpy(tmp + diff, current->string, current->chars);
				}
				free(current->string);
				current->string = tmp;
			}
		}
	}
}
