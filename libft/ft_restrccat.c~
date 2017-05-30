/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restrccat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:33:23 by adaly             #+#    #+#             */
/*   Updated: 2017/02/06 15:51:21 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*PURPOSE: TO REPLACE DST WITH A COPY OF ITSELF JOINED TO SRC AND FREE IT'S PREVIOUS INCARNATION. COPYING WILL GO UP TO BUT WILL NOT INCLUDE CHAR C*/

#include "libft.h"

char	*ft_restrccat(char **dst, char *src, char c)
{
	char *found;
	char *tmp;

	found = NULL;
	if (!(found = ft_strchr(src, c)))
	{
		ft_restrcat(dst, src);
	}
	else
	{
		tmp = ft_strsub(src, 0, (found - src));
		ft_restrcat(dst, tmp);
	}
	return (*dst);
}
