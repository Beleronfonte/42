/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:51:14 by ofernand          #+#    #+#             */
/*   Updated: 2024/03/28 13:27:13 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	size_to_find;

	i = 0;
	j = 0;
	size_to_find = 0;
	while (to_find[j] != '\0')
		j++;
	if (to_find[0] == 0)
		return (&str[0]);
	size_to_find = j;
	while (str[i] != '\0')
	{
		j = 0;
		if (to_find[0] == str[i])
		{
			while (to_find[j] == str[i + j] && j < size_to_find)
				j++;
			if (j == size_to_find)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
