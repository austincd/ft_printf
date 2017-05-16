/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 05:03:11 by adaly             #+#    #+#             */
/*   Updated: 2017/05/16 08:22:15 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_float_standard(t_pfconv *current, long double num, int base)
{
	int		exponent;
	char	*new;
	char	*exp;
	char	*temp;

	exponent = 0;
	while (num >= base)
	{
		num /= base;
		++exponent;
	}
	temp = ft_itoa_base(exponent, base);
	if (ft_strlen(temp) < base)
	{
		exp = ft_strjoin("0", temp);
		free(temp);
	}
	else
		exp = temp;
	new = ft_itoa_float(num, base);
	ft_restrcat(&new, "e");
	if (current->capitalized)
		new[ft_strlen(new) - 1] = 'E';
	ft_restrcat(&new, exp);
	free(exp);
	return (new);
}

char	*ft_float_normal(t_pfconv *current, long double num, int base)
{
	char	*new;
	char	*prefix;
	char	**invalid;

	prefix = ft_strdup("0x");
	invalid = ft_float_build_invalids(current->capitalized);
	if (current->capitalized)
		prefix[1] = 'X';
	if (base == 16)
		new = ft_strjoin(prefix, ft_itoa_float(num, base));
	else
		new = ft_itoa_float(num, base);
	return (new);
}

char	**ft_float_build_invalids(int capitalized)
{
	char **new;

	new = NULL;
	new = (char**)ft_memalloc(sizeof(char*) * 3);
	if (new)
	{
		if (capitalized)
		{
			new[0] = ft_strdup("INF");
			new[1] = ft_strdup("INFINITY");
			new[2] = ft_strdup("NAN");
		}
		else
		{
			new[0] = ft_strdup("inf");
			new[1] = ft_strdup("infinity");
			new[2] = ft_strdup("nan");
		}
	}
	return (new);
}
