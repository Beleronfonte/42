/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:48:35 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/03 17:48:37 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	if (argc >=1)
	{
		i = 0;
		while (argv[0][i])
			i++;
		write(1, argv[0], i);
	}
		write(1, "\n", 1);
}
