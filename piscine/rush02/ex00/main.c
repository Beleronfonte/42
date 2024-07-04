/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:10:10 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/07 19:57:23 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (validparameter(argv[1]))
			return (1);
		ft_choosen_dict("./numbers.dict", argv[1]);
	}
	else if (argc == 3)
	{
		if (validparameter(argv[2]))
			return (1);
		ft_choosen_dict(argv[1], argv[2]);
	}
	else
		write(2, "Error\n", 6);
}
