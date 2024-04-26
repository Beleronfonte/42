/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:32:02 by ofernand          #+#    #+#             */
/*   Updated: 2024/03/28 17:36:05 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	while (dest[i] != '\0')
		i++;
	if (size == 0)
		return (i - 1);
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size <= i)
		return (size + j);
	k = 0;
	while (src[k] != '\0' && k < j)
	{
		if (i < size -1)
			dest[i] = src[k];
		i++;
		j++;
		k++;
	}
	dest[i] = '\0';
	return (i);
}
