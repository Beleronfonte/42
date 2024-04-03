/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:56:45 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/02 17:41:53 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_error(char *base)
{
	int	length;
	int	i;

	length = 0;
	while (base[length] != '\0')
	{
		i = length + 1;
		if (base[length] == 43 || base[length] == 45 || base[length] == 32)
			return (1);
		while (base[i] != '\0')
		{
			if (base[length] == base[i])
				return (1);
			i++;
		}
		length++;
	}
	if (length < 2)
		return (1);
	else
		return (0);
}

/*needs tsting for ut this inside the whole function*/
void	ft_min_int(long min, int length, char *base)
{
	ft_putnbr_base((min / length), base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	length;
	int	error;
	int	c;
	
	error = ft_error(base);
	length = 0;
	while (base[length] != '\0')
		length++;
	if (error != 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			if (nbr == -2147483648)
				ft_min_int(2147483648, length, base);
			nbr = -nbr;
		}
		if (nbr > length)
			ft_putnbr_base((nbr / length), base);
		c = (nbr % length);
		write(1, &base[c], 1);
	}
}
