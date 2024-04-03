/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:29:22 by ofernand          #+#    #+#             */
/*   Updated: 2024/03/23 18:36:02 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putline(int x, int start, int middle, int end)
{
	int	i;

	i = 1;
	if (x > 0)
	{
		ft_putchar(start);
	}
	while (i < (x - 1))
	{
		ft_putchar(middle);
		i++;
	}
	if (x > 1)
	{
		ft_putchar(end);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	j;

	j = 1;
	if (x > 0 && y > 0)
	{
		ft_putline(x, 'A', 'B', 'C');
	}
	while (j < y - 1 && x > 0)
	{
		ft_putline(x, 'B', ' ', 'B');
		j++;
	}
	if (y > 1 && x > 0)
	{
		ft_putline(x, 'C', 'B', 'A');
	}
}
