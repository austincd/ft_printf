/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restrsub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:53:35 by adaly             #+#    #+#             */
/*   Updated: 2017/02/06 15:00:23 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_restrsub(char **str, char *strtwo, unsigned int start, size_t len)
{
	char *tmp;

	tmp = *str;
	*str = ft_strsub(strtwo, start, len);
	ft_strclr(tmp);
	free (tmp);
	return (*str);
}
