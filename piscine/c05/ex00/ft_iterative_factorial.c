/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:10:23 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/03 15:05:12 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	a;

	a = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (a > 1)
	{
		nb = nb * (a -1);
		a--;
	}
	return (nb);
}
