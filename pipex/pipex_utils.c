/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:04:36 by ofernand          #+#    #+#             */
/*   Updated: 2024/07/26 05:55:26 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(char **av)
{
	if (av[1] !exist)
		exit(error_msg()); //TODO
	if (av[4] !exist)
		//TODO: touch av[4]
}

char **get_path(char **envp)
{
	char	**path;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i],"PATH", 4) == 0)
		{
			path = ft_split(&envp[i][5], ':')
			break ;
		}
		i++;
	}
	return (path);
}

void	check_cmds(char **av, char **path) 
{
}

int error_msg()
{
	lorem ipsum
}
