/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:02:29 by ofernand          #+#    #+#             */
/*   Updated: 2024/05/20 10:38:59 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	new_char[1];
	int			i;

	i = 0;
	new_line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (new_char[0] == '\n')
		new_char[0] = 1;
	while (i <= BUFFER_SIZE && new_char[0] != '\n')
	{
		read(fd, new_char, 1);
		new_line[i] = new_char[0];
		if (new_char[0] == '\0')
			break;
		i++;
	}
	if (new_char[0] == '\0' && i == 0)
		return (NULL);
	new_line[i] = '\0';
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
