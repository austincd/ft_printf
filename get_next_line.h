/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 13:27:22 by adaly             #+#    #+#             */
/*   Updated: 2017/05/18 15:27:15 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define ARRAY_SIZE 32
# define BUFF_SIZE 2048

long long	ft_fd_search(long long fd, long long ***array);
long long	ft_read_line(int fd, char **storage, char **leftovers, char *buff);
int			ft_read_leftovers(char **leftovers, char **storage, char \
**line_end);
int			get_next_line(int fd, char **line);
void		ft_initialize_array(long long ****array);

#endif
