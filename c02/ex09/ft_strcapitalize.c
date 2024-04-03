/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:34:05 by ofernand          #+#    #+#             */
/*   Updated: 2024/03/27 15:58:19 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* check, by order, if is the first letter of the string or if the previous */
/* position is a space, a + or - symbol or a dot to convert to uppercase and */
/* then checks if previous position is not a space to covert to lowercase */
char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i -1] != 32) && (str[i] >= 65 && str[i] <= 90))
			str[i] = str[i] + 32;
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (str[i -1] <= 47)
				str[i] = str[i] - 32;
			else if (str[i -1] >= 58 && str[i -1] <= 64)
				str[i] = str[i] - 32;
			else if (str[i -1] >= 91 && str[i -1] <= 96)
				str[i] = str[i] - 32;
			else if (str[i -1] >= 123)
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
