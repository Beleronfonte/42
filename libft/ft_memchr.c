/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:00:09 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/17 12:22:38 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>

char	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*s;
	size_t			i;	

	a = (unsigned char)c;
	s = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (s[i] == a)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", ft_strchr("En un lugar de la mancha", '6'));
	printf("%s\n", strchr("En un lugar de la mancha", 96));
}*/
