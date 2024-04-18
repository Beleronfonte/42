/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:23:24 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/18 13:47:35 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] != '\0' && ((str[i] > 8 && str[i] < 14) || str[i] == 32))
		i++;
	if (str[i] != '\0' && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
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
