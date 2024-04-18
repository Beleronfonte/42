/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:17:31 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/18 12:22:18 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = str;
	while (i < n)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

/*int	main(void)
{
  char  test[21];
  char  *ptr;
  
  ptr = (char *)ft_memset(test, 'a', 20);
  printf("%s\n", ptr);
  ft_memset(test, 'b', 10);
  printf("%s\n", test);
}*/
