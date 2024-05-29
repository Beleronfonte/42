/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:02:29 by ofernand          #+#    #+#             */
/*   Updated: 2024/05/29 13:26:45 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_trim_line(char *buffer)
{
	char	*line;
	char	*new_buffer;
	int		i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	ft_strlcpy(line, buffer, i + 1);
	new_buffer = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	ft_strlcpy(new_buffer, buffer[i], ft_strlen(buffer) - i + 1);
	buffer = new_buffer;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	char		*new_str;
	static char	buffer;
	int			err_ctrl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (!ft_strchr(buffer, '\n') && err_ctrl != 0)
	{
		err_ctrl = read(fd, new_str, BUFFER_SIZE);
		if (err_ctrl == -1)
		{
			free(new_str);
			//free(buffer);
			return (NULL);
		}
		new_str[err_ctrl] = '\0';
		buffer = ft_strjoin(buffer, new_str);
	}
	new_line = ft_trim_line(buffer);
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
