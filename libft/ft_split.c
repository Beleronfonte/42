/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:23:40 by ofernand          #+#    #+#             */
/*   Updated: 2024/06/22 11:00:55 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	words;

	words = 0;
	while (*str && *str == c)
		str++;
	while (*str)
	{
		words++;
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
	}
	return (words);
}

static char	*get_word(const char *str, int start, int stop)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (stop - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < (stop - start))
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i]);
	free(ptr);
}

static void	split_str(char **ptr, const char *str, char c, int start)
{
	int	word;
	int	i;

	word = 0;
	i = start;
	while (str[i])
	{
		if (str[i + 1] == c || !str[i + 1])
		{
			ptr[word] = get_word(str, start, i + 1);
			if (!ptr[word])
				return (free_all(ptr));
			while (str[i + 1] && str[i + 1] == c)
				i++;
			start = i + 1;
			word++;
		}
		i++;
	}
	ptr[word] = NULL;
}

char	**ft_split(const char *str, char c)
{
	char	**ptr;
	int		start;

	ptr = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!ptr)
		return (NULL);
	start = 0;
	while (str[start] && str[start] == c)
		start++;
	split_str(ptr, str, c, start);
	return (ptr);
}
