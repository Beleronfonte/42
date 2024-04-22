/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
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

char	*ft_strchr(const char *s, int n)
{
	char	a;

	a = n;
	while (*s != '\0')
	{
		if (*s == a)
			return ((char *)s);
		s++;
	}
	if (*s == a)
		return ((char *)s);
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", ft_strchr("En un lugar de la mancha", '6'));
	printf("%s\n", strchr("En un lugar de la mancha", 96));
}*/
