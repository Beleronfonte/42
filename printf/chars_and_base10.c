/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_and_base10.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:22:51 by ofernand          #+#    #+#             */
/*   Updated: 2024/07/08 16:35:05 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
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

static int	len_num(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_itoa_for_i(int n)
{
	char		*str;
	int			len;
	long int	num;

	num = n;
	len = len_num(num);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (-1);
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[len - 1] = (num % 10) + '0';
		len--;
		num = num / 10;
	}
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_utoa(unsigned int n)
{
	char	*str;
	int		len;
	int		count;

	len = len_num(n);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (-1);
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len - 1] = (n % 10) + '0';
		len--;
		n = n / 10;
	}
	count = ft_putstr(str);
	free(str);
	return (count);
}
