/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:22:51 by ofernand          #+#    #+#             */
/*   Updated: 2024/07/26 03:31:56 by ofernand         ###   ########.fr       */
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

int	ft_ltohex(unsigned long n, char *base)
{
	int				len;
	char			*str;

	len = len_hex(n);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (-1);
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len - 1] = base[n % 16];
		len--;
		n = n / 16;
	}
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_ptr_dir(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") == -1)
		return (-1);
	count = ft_ltohex((unsigned long) ptr, "0123456789abcdef");
	if (count == -1)
		return (-1);
	return (count + 2);
}

char	*ft_calloc(int n, int size)
{
	char	*ptr;
	int		i;

	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
