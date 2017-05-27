/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_replace_after.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:26:08 by adaly             #+#    #+#             */
/*   Updated: 2017/05/27 00:47:52 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_replace_after(char **str, char *to_find, char *to_put, unsigned int after)
{
	char	*new;
	int		status;

	status = 0;
	if (str)
	{
		new = ft_strsub(*str, after, ft_strlen(*str + after));
		if (new)
		{
			if ((status = ft_find_replace(&new, to_find, to_put)))
			{
				ft_find_replace(str, *str + after, new);
			}
		}
	}
	return (status + after);
}
