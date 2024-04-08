/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:42:23 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/04 13:28:43 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnumbers(n1, n2, n3, n4)
{
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, " ", 1);
	write(1, &n3, 1);
	write(1, &n4, 1);
}

void	ft_second_pair(int n1, int n2, int n3, int n4)
{
	while (n3 <= '9')
	{
		while (n4 <= '9')
		{
			ft_putnumbers(n1, n2, n3, n4);
			if (n1 != '9' || n2 != '8' || n3 != '9' || n4 != '9')
				write(1, ", ", 2);
			n4++;
		}
		n3++;
		n4 = '0';
	}
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;
	int	n3;
	int	n4;

	n1 = '0';
	while (n1 <= '9')
	{
		n2 = '0';
		while (n2 <= '9')
		{
			n3 = n1;
			n4 = n2 +1;
			ft_second_pair(n1, n2, n3, n4);
			n2++;
		}
		n1++;
	}
}
