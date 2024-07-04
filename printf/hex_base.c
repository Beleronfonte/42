/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:22:51 by ofernand          #+#    #+#             */
/*   Updated: 2024/07/03 12:37:54 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_hex(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
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

void ft_ptr_dir(void *ptr)
{

}

int	ft_itohex(unsigned int n, char *base)
{
	int				len;
	char			*str;

	len = len_hex(n);
	str = calloc(sizeof(char), len + 1);
	if (!str)
		return ;
	while (n)
	{
		str[len - 1] = base[n % 16];
		if (len == 0)
			str[len] = base[n / 16];
		n = n / 16;
	}
	return (print_and_free(str));
}
