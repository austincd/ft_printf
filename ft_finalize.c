/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:30:42 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 19:46:29 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_free_wofinal(t_pfconv *current)
{
	if (current)
	{
		ft_strdel_plus(&(current->prefix));
		ft_strdel_plus(&(current->string));
		ft_strdel_plus(&(current->exponent));
		ft_strdel_plus(&(current->widthstr));
	}
}

static void	ft_finalize_one(t_pfconv *current)
{
	char	*final;

	final = NULL;
	if (ft_lowercase(current->type) == 'c')
	{
		current->final = current->string;
		current->string = NULL;
	}
	else
	{
		if (current->string)
		{
			ft_restrcat(&final, current->prefix);
			ft_restrcat(&final, current->widthstr);
			ft_restrcat(&final, current->string);
			ft_restrcat(&final, current->exponent);
			current->final = final;
		}
		current->chars = ft_strlen(current->final);
	}
}

static void	ft_finalize_two(t_pfconv *current)
{
	char	*final;

	final = NULL;
	if (current->string)
	{
		ft_restrcat(&final, current->widthstr);
		ft_restrcat(&final, current->prefix);
		ft_restrcat(&final, current->string);
		ft_restrcat(&final, current->exponent);
		current->final = final;
	}
	current->chars = ft_strlen(current->final);
}

static void	ft_finalize_three(t_pfconv *current)
{
	char	*final;

	final = NULL;
	if (current->string)
	{
		ft_restrcat(&final, current->prefix);
		ft_restrcat(&final, current->string);
		ft_restrcat(&final, current->exponent);
		ft_restrcat(&final, current->widthstr);
		current->final = final;
	}
	current->chars = ft_strlen(current->final);
}

static void	ft_finalize_c(t_pfconv *current)
{
	char	*final;
	int		wide;

	wide = 0;
	if (current->widthstr)
		wide = ft_strlen(current->widthstr);
	final = NULL;
	final = ft_strnew(current->chars + wide);
	if (current->flags[0])
	{
		ft_memcpy(final, current->string, current->chars);
		if (wide)
			ft_memcpy(final + current->chars, current->widthstr, wide);
	}
	else
	{
		if (wide)
			ft_memcpy(final, current->widthstr, wide);
		ft_memcpy(final + wide, current->string, current->chars);
	}
	current->final = final;
	current->chars += wide;
	
}

void		ft_finalize(t_pfconv *current)
{
	char	*temp;

	if (current)
	{
		if (current->string[0] == '-' && current->widthstr && !current->flags[0] && current->flags[3])
		{
			temp = current->widthstr;
			current->widthstr = ft_strjoin("-", current->widthstr);
			ft_strdel_plus(&temp);
			temp = ft_strdup(current->string + 1);
			ft_strdel_plus(&(current->string));
			current->string = temp;
			ft_finalize_one(current);
		}
		else if (current->type == 'S')
			ft_finalize_wstr(current);
		else if (current->flags[0] && ft_lowercase(current->type) != 'c')
			ft_finalize_three(current);
		else if (current->flags[4] && !current->flags[3] && ft_lowercase(current->type) != 'c')
			ft_finalize_two(current);
		else if (ft_lowercase(current->type) != 'n' && ft_lowercase(current->type) != 'c')
			ft_finalize_one(current);
		if (ft_lowercase(current->type) == 'c')
			ft_finalize_c(current);
		if (ft_lowercase(current->type) != 'n')
			ft_free_wofinal(current);
	}
}
