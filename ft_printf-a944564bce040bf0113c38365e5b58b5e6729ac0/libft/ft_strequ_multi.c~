/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ_multi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:28:23 by adaly             #+#    #+#             */
/*   Updated: 2017/04/15 15:28:34 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strequ_multi(char *str, char **table, int num)
{
	int index;

	index = 0;
	if (str && table)
	{
		while (index < num)
		{
			if (ft_strnequ(str, table[index], ft_strlen(table[index])))
				return (index);
			++index;
		}
	}
	return (-1);
}
