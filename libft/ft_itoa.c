/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:42:17 by ofernand          #+#    #+#             */
/*   Updated: 2024/05/02 11:45:24 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

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

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	num;

	num = n;
	len = len_num(num);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	str[len] = '\0';
	len--;
	while (num > 0)
	{
		str[len] = (num % 10) + '0';
		len--;
		num = num / 10;
	}
	return (str);
}

/*int	main(void)
{
	int		i;
	char	*str;

	i = 2828181;
	str = ft_itoa(i);
	printf("%s", str);
}*/
