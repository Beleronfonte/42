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
//#include <stdio.h>
//#include <string.h>

/*static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] != '\0' && dest_len < (size - 1))
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (dest_len);
}

/*int	main(void)
{
	//char	str[50] = "1234567890";
	char	dest[50] = "1234567890";
	char	src[] = "abcdefghijklmnopqrstuvwxyz";

	printf("la funcion original da %d, y la cadena mostrada es %s\n", 
	//y mi funcion da %d y mi cadena mostrada es %s\n, 
	strlcat(str, src, 20), str, ft_strlcat(dest, src, 50), dest);
}*/
