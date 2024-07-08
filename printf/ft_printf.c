/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:40:08 by ofernand          #+#    #+#             */
/*   Updated: 2024/07/08 16:36:25 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_and_count(const char *str, va_list args)
{
	int	count;

	if (*str == '%')
	{
		str++;
		if (*str == 'c' || *str == 's')
			count = ft_putstr(va_arg(args, char *));
		else if (*str == 'i' || *str == 'd')
			count = ft_itoa_for_i(va_arg(args, int));
		else if (*str == 'u')
			count = ft_utoa(va_arg(args, unsigned int));
		else if (*str == 'x')
			count = ft_ltohex(va_arg(args, unsigned int), "0123456789abcdef");
		else if (*str == 'X')
			count = ft_ltohex(va_arg(args, unsigned int), "0123456789ABCDEF");
		else if (*str == 'p')
			count = ft_ptr_dir(va_arg(args, void *));
		else if (*str == '%')
			count = ft_putchar(*str);
	}
	else
		count = ft_putchar(*str);
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		n_output;
	int		count;
	int		i;

	va_start(args, str);
	n_output = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		count = print_and_count(&str[i], args);
		if (count == -1)
			return (-1);
		n_output = n_output + count;
		if (str[i] == '%')
			i++;
		i++;
	}
	va_end(args);
	return (n_output);
}
