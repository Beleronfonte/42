/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:02:29 by ofernand          #+#    #+#             */
/*   Updated: 2024/05/06 13:15:59 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*new_line;
	char	*new_char;
	int		i;

	i = 0;
	new_line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	new_char = (char *)malloc(sizeof(char));
	while (i < BUFFER_SIZE && new_char[0] != '\n')
	{
		read(fd, new_char, 1);
		new_line[i] = new_char[0];
		i++;
	}
	//free(new_char);
	return (new_line);
}

int	main(void)
{
	int		fd;
	char	*to_print;

	fd = open("./numbers.dict", O_RDONLY);
	to_print = get_next_line(fd);
	printf("%s", to_print);
	to_print = get_next_line(fd);
	printf("%s", to_print);
	to_print = get_next_line(fd);
	printf("%s", to_print);
	to_print = get_next_line(fd);
	printf("%s", to_print);
	to_print = get_next_line(fd);
	printf("%s", to_print);
	to_print = get_next_line(fd);
	printf("%s", to_print);
	to_print = get_next_line(fd);
	printf("%s", to_print);
	free(to_print);
	close(fd);
}
