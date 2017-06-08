/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:04:13 by adaly             #+#    #+#             */
/*   Updated: 2017/06/07 20:34:10 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	char *str;
	long long a = -9223372036854775808;

	str = ft_strdup("michael!");
	ft_printf("drop%n that shit right now %n\n");
//	ft_printf("%#08x\nU is %U\n", 42, 5564);
//	ft_printf("hello %s number %c%0d\n", str, '#', 2);
}
