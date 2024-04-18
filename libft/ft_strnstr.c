/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:00:09 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/17 12:22:38 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[j] != '\0' && j < len)
	{
		i = 0;
		while (little[i] == big[j + i] && (j + i) < len
			&& little[i] != '\0')
			i++;
		if (little[i] == '\0')
			return ((char *)big + j);
		j++;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", ft_strnstr("En un lugar de la mancha", "lugar", 14));
}*/
