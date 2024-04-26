/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:17:31 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/19 13:22:18 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
/*void    *ft_memcpy(void *dest, const void *src, size_t n)
{
        size_t                  i;

        if (src == NULL || dest == NULL)
                return (NULL);
        i = 0;
        while (i < n)
        {
                ((char*)dest)[i] = ((const char *)src)[i];
                i++;
        }
        return (dest);
}*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src == NULL && dest == NULL)
		return (NULL);
	if (src < dest)
	{
		while (n > 0)
		{
			n--;
			((char *)dest)[n] = ((const char *)src)[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*int	main(void)
{
	char	*test;
	char	*ptr;
 
	test = malloc(sizeof (char) * 6); 
	ptr = "hello"; 
	ft_memcpy(test, ptr, 2);
	printf("%s\n", test);
}*/
