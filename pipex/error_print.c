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

#include "pipex.h"

static int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

static int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

static int	print_and_count(const char *str, va_list args)
{
	int	count;

	if (*str == '%' && *(str + 1))
	{
		str++;
		if (*str == 'c' || *str == 's')
			count = ft_putstr(va_arg(args, char *));
		else if (*str == '%')
			count = ft_putchar(*str);
	}
	else
		count = ft_putchar(*str);
	return (count);
}

int	error_print(char const *str, ...)
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
