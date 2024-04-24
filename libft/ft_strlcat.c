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

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
  src_len = ft_strlen(src);
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
