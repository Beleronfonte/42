/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:29:39 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/10 16:59:08 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*map;
	char	symbol[3];
	int		number;

	i = 1;
	while (argv[i])
	{
		map = ft_filereader(argv[i]);
		number = ft_char(map, symbol);
		if (ft_valid_file(map, symbol) == 0 && map != NULL)
			ft_matrix_magic(map, symbol, number);
		else
			write(2, "map error", 9);
		free(map);
		write(1, "\n", 1);
		i++;
	}
	return (argc);
}
