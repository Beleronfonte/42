/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:10:59 by meghribe          #+#    #+#             */
/*   Updated: 2024/04/10 17:35:00 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n && src[i] == '\0')
	{
		while (dest[i] != '\0')
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}

int	ft_atoi(char *str)
{
	int		i;
	int		check_negative;
	int		result;

	check_negative = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			check_negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result *= check_negative;
	return (result);
}

int	ft_char(char *str, char *symbol)
{
	int		number;
	char	*number_before;

	number = ft_strlen(str);
	symbol[2] = str[number - 1];
	symbol[1] = str[number - 2];
	symbol[0] = str[number - 3];
	number_before = (char *)malloc(sizeof(char) * number - 3);
	if (number_before == NULL)
		return (1);
	ft_strncpy(number_before, str, number - 3);
	number = ft_atoi(number_before);
	free(number_before);
	return (number);
}
