/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:29:51 by adaly             #+#    #+#             */
/*   Updated: 2017/05/27 03:22:07 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_replace_char(char **p_big, char *p_little, char c, unsigned int after)
{
	char	*new_str;
	char	*old_loc;
	int		old_len;
	int		ret;

	new_str = NULL;
	if (p_big)
	{
		old_len = ft_strlen(p_little);
		old_loc = ft_strstr(*p_big + after, p_little);
		if (old_loc)
		{
			new_str = ft_strnew(ft_strlen(*p_big + after) + after - ft_strlen(p_little));
			if (new_str)
			{
				ft_memmove(new_str, *p_big, (old_loc - *p_big));
				ret = old_loc - *p_big;
				new_str[ret] = c;
				++ret;
				ft_strcat(new_str, (old_loc + old_len));
				free(*p_big);
				*p_big = new_str;
				return (ret);
			}
		}
	}
	return (0);
}
