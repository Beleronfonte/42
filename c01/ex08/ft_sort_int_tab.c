/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:19:53 by ofernand          #+#    #+#             */
/*   Updated: 2024/03/25 18:41:50 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= (size -2))
		{
			if (tab[j] > tab[j +1])
			{
				swap = tab[j];
				tab[j] = tab[j +1];
				tab[j +1] = swap;
			}
			j++;
		}
		i++;
	}
}
