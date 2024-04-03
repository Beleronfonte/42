/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:23:24 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/02 16:55:40 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	number;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] != '\0' && str[i] < 48)
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	number = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * sign);
}
