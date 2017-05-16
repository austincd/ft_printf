/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 14:14:49 by adaly             #+#    #+#             */
/*   Updated: 2017/04/15 15:52:12 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	**str;
	t_pfconv	*new;
	int			index;

	index = 0;
	str = (char**)ft_memalloc(sizeof(char*) * 10);
	str[0] = ft_strdup("%2$-+ 12.4s");
	str[1] = ft_strdup("%+ 12.4s");
	str[2] = ft_strdup("%2$-+ 12.*u");
	str[3] = ft_strdup("%2$-+ *.*L");
	str[4] = ft_strdup("%*.4i");
	str[5] = ft_strdup("%-.*4hhd");
	str[6] = ft_strdup("%2$-+*.*hs");
	str[7] = ft_strdup("%.*u");
	str[8] = ft_strdup("%- 2.*La");
	str[9] = ft_strdup("%hi");
	while (index < 10)
	{
		if (str[index][0] == '%')
		{
			new = ft_conversion_parsing(str + index);
			printf("LENGTH: %d\nPRECISION: %d\nWIDTH: %d\nCAPITALIZED: %d\nTYPE:\
%c\nPARAMETER: %d\nFLAGS1: %d\nFLAGS2: %d\nFLAGS3: %d\nFLAGS4:\
%d\nFLAGS5: %d\nSTRING: %s\n", new->length, new->precision, new->width,\
					new->capitalized, new->type, new->parameter, new->flags[0], new->flags[1],\
					 new->flags[2], new->flags[3], new->flags[4], new->string);

		}
		++index;
	}
}
