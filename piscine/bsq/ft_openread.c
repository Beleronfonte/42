/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:05:43 by meghribe          #+#    #+#             */
/*   Updated: 2024/04/10 16:32:42 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_length(char *file_name)
{
	int		counter_id;
	int		i;
	char	c;

	i = 0;
	counter_id = open(file_name, O_RDONLY);
	if (counter_id == -1)
		return (1);
	while (read(counter_id, &c, 1) == 1)
		i++;
	close(counter_id);
	return (i);
}

char	*ft_filereader(char *file_name)
{
	int				file_id;
	int				file_length;
	char			*map;

	file_length = ft_length(file_name);
	if (file_length == 0)
		return (NULL);
	file_id = open(file_name, O_RDONLY);
	if (file_id == -1)
		return (NULL);
	map = (char *)malloc((file_length) * sizeof(char));
	if (!map)
		return (NULL);
	read(file_id, map, file_length);
	close(file_id);
	return (map);
}
