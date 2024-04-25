/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:17:31 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/18 12:22:18 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
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
