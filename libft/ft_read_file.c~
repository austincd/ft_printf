/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:13:26 by adaly             #+#    #+#             */
/*   Updated: 2017/04/19 14:26:02 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_read_file(int fd, long long offset, long long size)
{
	void		*reserved;
	int			bytes_per_cycle;
	long long	cycle;

	cycle = 0;
	bytes_per_cycle = 512;
	reserved = NULL;
	reserved = (void*)ft_memalloc(size);
	if (reserved)
	{
		lseek(fd, offset, SEEK_SET);
		while (size)
		{
			if (size > bytes_per_cycle)
			{
				read(fd, reserved + (bytes_per_cycle * cycle), bytes_per_cycle);
				size -= bytes_per_cycle;
			}
			else if (size <= bytes_per_cycle)
			{
				read(fd, reserved + (bytes_per_cycle * cycle), size);
				size -= size;
			}
			++cycle;
		}		
	}
	return (reserved);
}
