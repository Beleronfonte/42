/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:40:57 by ofernand          #+#    #+#             */
/*   Updated: 2024/04/30 16:19:27 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	count_words(char const	*str, char c)
{
	int	words;

	if (!str)
		return (0);
	words = 0;
	while (*str)
	{
		if (*str == c)
		{
			words++;
			while (*str == c)
				str++;
		}
		else
			str++;
	}
	words++;
	return (words);
}

static void	free_all(char **ptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static void	split_str(char **ptr, char *str, char c, int words)
{
	int		i;
	char	*next_sep;

	i = 0;
	while (i < (words - 1))
	{
		next_sep = ft_strchr(str, c);
		ptr[i] = ft_substr(str, 0, next_sep - str);
		if (!ptr[i])
		{
			free_all(ptr, i);
			return ;
		}
		while (*next_sep == c)
			next_sep++;
		str = next_sep;
		i++;
	}
	ptr[i] = ft_strdup(str);
	if (!ptr[i])
	{
		free_all(ptr, i);
		return ;
	}
	ptr[++i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	aux[2];
	char	**ptr;
	int		words;

	aux[0] = c;
	aux[1] = '\0';
	str = ft_strtrim(s, aux);
	if (!str)
		return (NULL);
	words = count_words(str, c);
	ptr = ft_calloc(words + 1, sizeof(char *));
	if (ptr)
	{
		if (words == 0)
			ptr[0] = NULL;
		else
			split_str(ptr, str, c, words);
	}
	free(str);
	return (ptr);
}

/*int	main(void)
{
	char	*s;
	char	c;
	char	**r;
	int		i;

	i = 0;
	s = "En un lugar de la mancha";
	c = ' ';
	r = ft_split(s, c);
	while (r[i])
	{
		printf("%s\n", r[i]);
		i++;
	}
	free_all(r, i);
}*/
