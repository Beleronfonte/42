/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:13:32 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/03 16:33:33 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	else
		return (0);
}
