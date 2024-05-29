/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:02:29 by ofernand          #+#    #+#             */
/*   Updated: 2024/05/29 11:48:50 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	new_char[1];
	int			i;
	int			err_ctrl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	new_line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (new_char[0] == '\n')
		new_char[0] = ' ';
	while (i <= BUFFER_SIZE && new_char[0] != '\n')
	{
		err_ctrl = read(fd, new_char, 1);
		if (err_ctrl == -1)
			return (NULL);
		if (err_ctrl == 0 && i == 0)
			return (NULL);
		if (err_ctrl == 0 && i != 0)
			return (new_line);
		new_line[i] = new_char[0];
		i++;
	}
	return (new_line);
}

int	main(void)
{
	int		fd;
	char	*to_print;

	fd = open("./numbers.dict", O_RDONLY);
	to_print = get_next_line(fd);
	printf("%s", to_print);
	free(to_print);
	close(fd);
}
