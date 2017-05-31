/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 04:32:43 by adaly             #+#    #+#             */
/*   Updated: 2017/05/30 20:01:56 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_three(unsigned int c)
{
	unsigned long	full_char;
	unsigned char	*ptr;

	ptr = (unsigned char*)&(full_char);
	ptr[0] = 0360 | (c >> 18);
	ptr[1] = 0200 | ((c >> 12) & 077);
	ptr[2] = 0200 | ((c >> 6) & 077);
	ptr[3] = 0200 | (c & 077);
/*	printf("ptr0= %o\nptr1= %o\nptr2= %o\nptr3= %o\n", ptr[0], ptr[1], ptr[2], ptr[3]);
	printf("temp = %lo\n", temp >> 14);

	full_char = full_char | (temp << 6);
	temp = c & and[2];
	printf("ptr0= %o\nptr1= %o\nptr2= %o\nptr3= %o\n", ptr[0], ptr[1], ptr[2], ptr[3]);
	printf("%lo\n", full_char);
	printf("temp = %lo\n", temp);
	full_char = full_char | (temp << 4);
	temp = c & and[1];
	printf("ptr0= %o\nptr1= %o\nptr2= %o\nptr3= %o\n", ptr[0], ptr[1], ptr[2], ptr[3]);
	printf("%lo\n", full_char);
	printf("temp = %lo\n", temp);
	full_char = full_char | (temp << 3);
	printf("ptr0= %o\nptr1= %o\nptr2= %o\nptr3= %o\n", ptr[0], ptr[1], ptr[2], ptr[3]);
	temp = c & and[0];
	printf("%lo\n", full_char);
	printf("temp = %lo\n", temp);
	full_char = full_char | temp;
	printf("ptr0= %o\nptr1= %o\nptr2= %o\nptr3= %o\n", ptr[0], ptr[1], ptr[2], ptr[3]);
	printf("%lo\n", full_char);*/
	return (full_char);
}

static unsigned long	ft_two(unsigned int c)
{
	unsigned long	full_char;
	unsigned char	*ptr;

	ptr = (unsigned char*)&(full_char);
	ptr[0] = 0340 + ((c >> 12));
	ptr[1] = 0200 | ((c >> 6) & 077);
	ptr[2] = 0200 | (c & 077);
	ptr[3] = 0;
	//printf("ptr0= %o\nptr1= %o\nptr2= %o\n", ptr[0], ptr[1], ptr[2]);
/*	printf("%o\n", c);
	full_char = 0340200200;
	temp = (c & and[2]) >> 12;
	printf("temp = %lo\n", temp);
	printf("%lo\n", temp + 0340);
	full_char = full_char | temp << 18;
	printf("%lo\n", full_char);
	temp = (c & and[1]) >> 6;
	printf("temp = %lo\n", temp);
	full_char = full_char | temp << 9;
	printf("%lo\n", full_char);
	temp = c & and[0];
	printf("temp = %lo\n", temp);
	full_char = full_char | temp;
	printf("%lo\n", full_char);*/
	return (full_char);
}

static unsigned long	ft_one(unsigned int c)
{
	unsigned long	full_char;
	unsigned char	*ptr;

	ptr = (unsigned char*)&(full_char);
	ptr[0] = 0300 | (c >> 6);
	ptr[1] = 0200 | (c & 077);
	ptr[2] = 0;
	ptr[3] = 0;
/*	temp = (c & and[1]) >> 6;
	printf("temp = %lo\n", temp);
	printf("%lo\n", full_char);
	full_char = full_char | temp << 9;
	temp = c & and[0];
	printf("temp = %lo\n", temp);
	printf("%lo\n", full_char);
	full_char = full_char | temp;*/
	return (full_char);
}

unsigned long	ft_char_expand(unsigned long c)
{
	int				full_char;
	int				index;

	index = 1;
	full_char = c;
	if (index)
	{
		if (c >= 65536 && c <= 524287)
			full_char = ft_three(c);
		if (c >= 2048 && c <= 65535)
			full_char = ft_two(c);
		if (c >= 128 && c <= 2047)
			full_char = ft_one(c);
	}
	return (full_char);
//	ptr = ((unsigned char*)&full_char);
}
