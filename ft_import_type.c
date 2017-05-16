/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 06:14:45 by adaly             #+#    #+#             */
/*   Updated: 2017/05/16 06:35:57 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_import_type(t_pfconv *current)
{
	if (current)
	{
		if (current->import_type == 'i')
		{
			if (current->length == 2)
				current->import_type == 'l';
			if (current->length == 3)
				current->import_type == 'm';
			if (current->length == 5)
				current->import_type == 'z';
			if (current->length == 6)
				current->import_type == 'j';
			if (current->length == 7)
				current->import_type == 't';
		}
		if (current->import_type == '2')
		{
			if (current->length == 2)
				current->import_type = 'D';
			if (current->length == 5)
				current->import_type = 'L';
		}
	}
}
