/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:56:44 by ofernand          #+#    #+#             */
/*   Updated: 2024/07/31 10:57:12 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(char *str, char c)
{
	int	words;

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

static char	*get_word(char *str, int start, int stop)
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

static char	**free_all(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static char	**split_str(char **ptr, char *str, char c, int start)
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
	return (ptr);
}

char	**ft_split(char *str, char c)
{
	char	**ptr;
	int		start;

	if (str == NULL)
		return (NULL);
	ptr = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!ptr)
		return (NULL);
	start = 0;
	while (str[start] && str[start] == c)
		start++;
	ptr = split_str(ptr, str, c, start);
	return (ptr);
}
