/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:22:51 by ofernand          #+#    #+#             */
/*   Updated: 2024/06/03 12:37:54 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int	i;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

char	*ft_calloc(int n, int size)
{
	char	*ptr;
	int		i;

	ptr = malloc(n * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
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

void	ft_itoa_for_i(int n)
{
	char		*str;
	int			len;
	long int	num;

	num = n;
	len = len_num(num);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return ;
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
	ft_putstr(str);
	free(str);
}

void	ft_utoa(unsigned int n)
{
	char		*str;
	int			len;

	len = len_num(n);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return ;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len - 1] = (n % 10) + '0';
		len--;
		n = n / 10;
	}
	ft_putstr(str);
	free(str);
}
