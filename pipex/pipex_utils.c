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

void	check_files(char **av, int *fd)
{
	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] < 0)
		exit(1);
		//exit(error_msg()); //TODO
	fd[1] = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
		if (fd[1] < 0)
		exit(1);
		//exit(error_msg()); //TODO
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
	exit(1);
	//exit(error_msg(); //cmd_tested do not exist
}

/*int error_msg()
{
	lorem ipsum
}*/
