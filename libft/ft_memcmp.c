/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:17:31 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/22 12:22:18 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*str1;
	unsigned const char	*str2;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (str1[i] == str2[i] && str1[i] != '\0' && i < n)
	{
		i++;
		if (i == n)
			return (0);
	}
	return ((int)(str1[i] - str2[i]));
}

/*int	main(void)
{
	char	*test;
	char	*ptr;
 
	test = "HELLO"; 
	ptr = "HELA"; 
	printf("%d\n",ft_memcmp(test, ptr, 4));
}*/
