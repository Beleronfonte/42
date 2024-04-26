/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:44:16 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/08 17:26:11 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_comb(int count, int n, int *number)
{
	int	adder;
	int	last_n;

	while (count < n)
	{
		write(1, &number[count], 1);
		count++;
	}
	write(1, ", ", 2);
	count--;
	number[count]++;
	if (number[count] > 57)
	{
		adder = 0;
		while (number[count - adder] > (57 - adder) && adder < n)
		{
			adder++;
			number [count - adder]++;
		}
		while (adder >= 0)
		{
			last_n = number[count - adder];
			adder--;
			number[count - adder] = last_n +1;
		}
	}
}

void	ft_print_combn(int n)
{
	int	count;
	int	number[9];

	number[0] = 48;
	count = 1;
	while (count < n)
	{
		number[count] = number[count -1] + 1;
		count++;
	}
	while (number[0] <= (58 - n))
	{
		count = 0;
		ft_comb(count, n, number);
	}
}
/*void	ft_comb(int count, int n, int *number)
{
	int	adder;

	while (count < n)
		{
			write(1, &number[count], 1);
			count++;
		}
	write(1, ", ", 2);
	number[count -1]++;
	if (number[count -1] > 57)
		{
			adder = 1;
			while (number[count - adder] > (58 - adder) && adder < n)
			{
				adder++;
				number [count - adder]++;
			}
			while (adder > 0)
			{
				adder--;
				number [count - adder] = number[count - adder + 1] +1;
			}
		}
}*/
