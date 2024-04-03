/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:19:15 by ofernand          #+#    #+#             */
/*   Updated: 2024/03/21 15:36:51 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	i;

	if (n >= 0)
	{
		i = 'P';
	}
	else
	{
		i = 'N';
	}
	write(1, &i, 1);
}

/*int	main(void)
{
	ft_is_negative(5);
	ft_is_negative(0);
	ft_is_negative(-5);
	return (0);
	}*/
