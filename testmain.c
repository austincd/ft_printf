/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:04:13 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 19:41:13 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	char *str;

	str = ft_strdup("michael!");
//	printf("%o, %ho, %hho", -42, -42, -42);
	printf("yours:{%05d}\n", -42);
//	printf("lnull is %d\n", L"null");
	ft_printf("mine:{%05d}\n", -42);
//	printf("yours{%3c}\n", 0);
//	ft_printf("mine{%3c}\n", 0);
//	ft_printf("drop%n that shit right now %n\n");
//	ft_printf("%#08x\nU is %U\n", 42, 5564);
//	ft_printf("hello %s number %c%0d\n", str, '#', 2);
}
