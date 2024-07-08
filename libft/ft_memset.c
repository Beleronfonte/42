/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:24:35 by ofernand          #+#    #+#             */
/*   Updated: 2024/07/01 17:02:31 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

<<<<<<< HEAD
=======
	if (!str)
		return (NULL);
>>>>>>> curro
	i = 0;
	s = str;
	while (i < n)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
