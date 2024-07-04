/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:29:03 by ofernand          #+#    #+#             */
/*   Updated: 2024/06/18 18:29:10 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int n)
{
	char	a;
	int		i;

	if (!s)
		return (NULL);
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
