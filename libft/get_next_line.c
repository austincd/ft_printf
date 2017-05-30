/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 20:16:02 by adaly             #+#    #+#             */
/*   Updated: 2017/04/21 16:50:36 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	static long long	***array;
	char				*buff;
	long long			index;

	if (fd >= 0 && line)
	{
		if (!array)
			ft_initialize_array(&array);
		index = ft_fd_search(fd, array);
		if (index >= 0)
		{
			buff = ft_strnew(BUFF_SIZE);
			array[0][1][index] = ft_read_line(fd, (char**)&(array[1][index])\
			, (char**)&(array[2][index]), buff);
			*line = (char*)(array[1][index]);
			return (array[0][1][index]);
		}
		else if (index == -1)
		{
			ft_longlongcat(array[0][0], fd);
			return (get_next_line(fd, line));
		}
	}
	return (-1);
}

long long	ft_read_line(int fd, char **storage, char **leftovers, char *buff)
{
	char	*line_end;
	int		status[2];

	ft_strclr(*storage);
	if (ft_read_leftovers(leftovers, storage, &line_end) == 1)
		return (1);
	while ((status[0] = read(fd, buff, BUFF_SIZE)))
	{
		status[1] = status[0];
		if (status[0] < 0)
			return (-1);
		if ((line_end = ft_strchr(buff, '\n')))
		{
			ft_restrccat(storage, buff, '\n');
			ft_restrcat(leftovers, (line_end + 1));
			free(buff);
			return (1);
		}
		else
			ft_restrcat(storage, buff);
		ft_strclr(buff);
	}
	if (**storage)
		return (1);
	return (0);
}

void		ft_initialize_array(long long ****array)
{
	(*array) = (long long***)ft_memalloc(sizeof(long long**) * 3);
	(*array)[0] = (long long**)ft_memalloc(sizeof(long long*) * 3);
	(*array)[0][0] = (long long*)ft_memalloc(sizeof(long long) * ARRAY_SIZE);
	(*array)[0][1] = (long long*)ft_memalloc(sizeof(long long) * ARRAY_SIZE);
	(*array)[1] = (long long**)ft_memalloc(sizeof(long long*) * ARRAY_SIZE);
	(*array)[2] = (long long**)ft_memalloc(sizeof(long long*) * ARRAY_SIZE);
}

int			ft_read_leftovers(char **leftovers, char **storage, char **line_end)
{
	if (*leftovers)
	{
		ft_restrccat(storage, *leftovers, '\n');
		if ((*line_end = ft_strchr(*leftovers, '\n')) && *storage)
		{
			ft_restrsub(leftovers, *line_end + 1, 0, ft_strlen(*line_end + 1));
			return (1);
		}
		else
			ft_strclr(*leftovers);
	}
	return (0);
}

long long	ft_fd_search(long long fd, long long ***array)
{
	long long counter;

	counter = 0;
	if (array)
	{
		while (counter < ARRAY_SIZE)
		{
			if (array[0] && array[1])
			{
				if (array[0][0][counter] == fd)
					return (counter);
			}
			++counter;
		}
		return (-1);
	}
	return (-2);
}
