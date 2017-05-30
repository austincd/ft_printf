/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:29:51 by adaly             #+#    #+#             */
/*   Updated: 2017/05/27 04:32:09 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_replace(char **p_big, char *p_little, char *p_new)
{
	char	*new_str;
	char	*old_loc;
	int		old_len;
	int		ret;

	new_str = NULL;
	if (p_big)
	{
		old_len = ft_strlen(p_little);
		old_loc = ft_strstr(*p_big, p_little);
		if (old_loc)
		{
			new_str = ft_strnew(ft_strlen(*p_big) + \
			ft_strlen(p_new) - ft_strlen(p_little));
			if (new_str)
			{
				ft_strncat(new_str, *p_big, (old_loc - *p_big));
				ft_strcat(new_str, p_new);
				ret = ft_strlen(new_str);
				if (!*p_new)
					++ret;
				ft_strcat(new_str + ret, (old_loc + old_len));
				free(*p_big);
				*p_big = new_str;
				return (ret);
			}
		}
	}
	return (0);
}
