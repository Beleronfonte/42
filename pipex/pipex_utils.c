/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:00:27 by ofernand          #+#    #+#             */
/*   Updated: 2024/07/31 12:08:27 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(char **av, int *fd)//faltan access?
{
	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] < 0)
		error_msg(errno, av[1]);
	fd[1] = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (fd[1] < 0)
		error_msg(errno, av[4]);
	return ;
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
			path = ft_split(&envp[i][5], ':');
			break ;
		}
		i++;
	}
	return (path);
}

char	*check_cmd(char *cmd_tested, char **path) 
{	
	char	*tmp;
	char	*cmd;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		cmd = ft_strjoin(tmp, cmd_tested);
		free(tmp);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		path++;
		free(cmd);
	}
	error_msg(errno, cmd_tested); 
	return (NULL);
}

void error_msg(int error, char *str)
{
	//error_printf("pipex: %s", str);
	perror("pipex");
	str--;
	exit (error);
}
