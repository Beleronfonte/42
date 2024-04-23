/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:00:09 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/17 12:22:38 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strrchr(const char *s, int n)
{
	char	a;
	int		i;

	a = n;
	i = ft_strlen(s);
	if (s[i] == a)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", ft_strchr("En un lugar de la mancha", '6'));
	printf("%s\n", strchr("En un lugar de la mancha", 96));
}*/
