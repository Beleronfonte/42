/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:02:29 by ofernand          #+#    #+#             */
/*   Updated: 2024/05/30 14:11:01 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_trim_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	ft_strlcpy(line, buffer, i + 2);
	return (line);
}

static char	*ft_keep_surplus(char *buffer)
{
	char	*new_buffer;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n')
		i++;
	new_buffer = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i));
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	ft_strlcpy(new_buffer, &buffer[i + 1], ft_strlen(buffer) - i);
	free(buffer);
	return (new_buffer);
}

static char	*ft_get_buffer(int fd, char *buffer)
{
	char		*tmp_str;
	int			byte_ctrl;

	tmp_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp_str)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && byte_ctrl != 0)
	{
		byte_ctrl = read(fd, tmp_str, BUFFER_SIZE);
		if (byte_ctrl == -1)
		{
			free(buffer);
			free(tmp_str);
			return (NULL);
		}
		tmp_str[byte_ctrl] = '\0';
		buffer = ft_strjoin(buffer, tmp_str);
	}
	//free(tmp_str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	new_line = ft_trim_line(buffer);
	buffer = ft_keep_surplus(buffer);
	return (new_line);
}

int	main(void)
{
	int		fd;
	char	*to_print;

	fd = open("./numbers.dict", O_RDONLY);
	to_print = get_next_line(fd);
	printf("%s", to_print);
	close(fd);
}
