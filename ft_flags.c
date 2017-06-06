/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 21:34:57 by adaly             #+#    #+#             */
/*   Updated: 2017/06/05 19:40:32 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hash(t_pfconv *current)
{
	char	*temp;

	temp = NULL;
	if (current->flags[4])
	{
		if (ft_tolower(current->type == 'o') && ft_atoi(current->string))
			temp = ft_strjoin("0", current->string);
		if (current->type == 'x')
			temp = ft_strjoin("0x", current->string);
		if (current->type == 'X')
			temp = ft_strjoin("0X", current->string);
		if (temp)
		{
			ft_strdel_plus(&(current->string));
			current->string = temp;
			current->chars = ft_strlen(current->string);
		}
	}
}

void	ft_space(t_pfconv *current)
{
	char *ints;
	char *temp;

	ints = ft_strdup("idID");
	if (current)
	{
		if (!current->flags[1] && current->flags[2] && \
		ft_strchr(ints, current->type))
		{
			if (!ft_strchr(current->string, '-') && current->width \
			< (int)ft_strlen(current->string))
			{
				temp = current->string;
				current->string = ft_strjoin(" ", current->string);
				current->chars = ft_strlen(current->string);
				ft_strdel_plus(&temp);
			}
			else if (!ft_strchr(current->string, '-') && \
			current->width == (int)ft_strlen(current->string))
				current->string[0] = ' ';
		}
	}
	ft_strdel_plus(&ints);
}

void	ft_plus(t_pfconv *current)
{
	char ints[5];
	char *temp;

	ints[0] = 'i';
	ints[1] = 'I';
	ints[2] = 'd';
	ints[3] = 'D';
	ints[4] = 0;
	if (current)
	{
		if (current->flags[1] && ft_strchr(ints, current->type))
		{
			if (!ft_strchr(current->string, '-') && \
			current->width < (int)ft_strlen(current->string))
			{
				temp = current->string;
				current->string = ft_strjoin("+", current->string);
				current->chars = ft_strlen(current->string);
				ft_strdel_plus(&temp);
			}
			else if (!ft_strchr(current->string, '-') \
			&& current->width == (int)ft_strlen(current->string))
				current->string[0] = '+';
		}
	}
}

void	ft_zero(t_pfconv *current)
{
	char ints[5];
	char *temp;

	ints[0] = 'i';
	ints[1] = 'I';
	ints[2] = 'd';
	ints[3] = 'D';
	ints[4] = 0;
	if (current)
	{
		if (current->flags[3] && ft_strchr(ints, current->type))
		{
			printf("hello\n");
			while ((temp = ft_strchr(current->string, ' ')))
				*temp = '0';
			current->flags[3] = 0;
		}
	}
}
