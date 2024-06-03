/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:40:08 by ofernand          #+#    #+#             */
/*   Updated: 2024/06/03 12:49:06 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;

	va_start(args, str);

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c' || *str == 's')
				ft_putstr(va_arg(args, char *));
			/*else if (*str == 'd' || *str == 'i' || *str == 'u')
				//imprimir base 10
			else if (*str == 'p' || *str == 'x' || *str == 'X')
				//imprimir base 16*/
			else if (*str == '%')
				ft_putchar(*str);
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (0);
}
