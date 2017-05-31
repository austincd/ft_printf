/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 21:34:57 by adaly             #+#    #+#             */
/*   Updated: 2017/05/31 15:02:24 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hash(t_pfconv *current)
{
	char	*temp;

	temp = NULL;
	if (current->flags[4])
	{
		if (current->type == 'o')
			temp = ft_strjoin("0", current->string);
		if (current->type == 'x')
			temp = ft_strjoin("0x", current->string);
		if (current->type == 'X')
			temp = ft_strjoin("0X", current->string);
		if (temp)
		{
			free(current->string);
			current->string = temp;
		}
	}
}
void	ft_space(t_pfconv *current)
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
		if (!current->flags[1] && current->flags[2] && ft_strchr(ints, current->type))
		{
			if (!ft_strchr(current->string, '-') && current->width < (int)ft_strlen(current->string))
			{
				temp = current->string;
				current->string = ft_strjoin(" ", current->string);
				current->chars = ft_strlen(current->string);
				free (temp);
			}
			else if (!ft_strchr(current->string, '-') && current->width == (int)ft_strlen(current->string))
			{
				current->string[0] = ' ';
			}
		}
	}
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
			if (!ft_strchr(current->string, '-') && current->width < (int)ft_strlen(current->string))
			{
				temp = current->string;
				current->string = ft_strjoin("+", current->string);
				current->chars = ft_strlen(current->string);
				free (temp);
			}
			else if (!ft_strchr(current->string, '-') && current->width == (int)ft_strlen(current->string))
			{
				current->string[0] = '+';
			}
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
			while ((temp = ft_strchr(current->string, ' ')))
				*temp = '0';
		}
	}
}

void	ft_width(t_pfconv *current)
{
	char			*tmp;
//	char			*new;
	unsigned int	diff;

	diff = current->width - current->chars;
	tmp = NULL;
//	new = NULL;
	if (current)
	{
		if (current->string && current->width >= 0)
		{
			if (current->chars < current->width)
			{
				tmp = ft_strnew(current->width);
				if (current->flags[0] == 1)
				{
					ft_memcpy(tmp, current->string, current->chars);
					ft_memset(tmp + current->chars, ' ', diff);
				}
				else
				{
					ft_memset(tmp, ' ', diff);
					ft_memcpy(tmp + diff, current->string, current->chars);
				}
				free(current->string);
				current->string = tmp;
				current->chars = ft_strlen(current->string);
			}
		}
	}
}
