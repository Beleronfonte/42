/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:00:27 by ofernand          #+#    #+#             */
/*   Updated: 2024/08/12 19:47:39 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	check_files(char **av, t_list aux)
{
	aux.fd[1] = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (aux.fd[1] < 0)
		error_msg(errno, NULL, av[4]);
	aux.fd[0] = open(av[1], O_RDONLY);
	if (aux.fd[0] < 0)
	{
		close(aux.fd[1]);
		error_msg(errno, NULL, av[1]);
	}
	return (aux);
}

char	**get_path(t_list aux, char **envp)
{
	char	**path;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path = ft_split(&envp[i][5], ':');
			if (!path)
			{
				close(aux.fd[0]);
				close(aux.fd[1]);
				error_msg(errno, NULL, NULL);
			}
			break ;
		}
		i++;
	}
	return (path);
}

char	*check_cmd(t_list aux, char *cmd_tested, char **path)
{
	char	*tmp;
	char	*cmd;
	char	**cmd_arg;

	if (!path)
	{
		close_and_free(aux, NULL);
		error_msg(-1, "not PATH found", NULL);
	}
	cmd_arg = ft_split(cmd_tested, ' ');
	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		cmd = ft_strjoin(tmp, cmd_arg[0]);
		free(tmp);
		if (access(cmd, X_OK) == 0)
		{
			free_all(cmd_arg);
			return (cmd);
		}
		path++;
		free(cmd);
	}
	free_all(cmd_arg);
	return (NULL);
}

void	error_msg(int error, char *msg, char *file)
{
	if (msg && !file)
		error_print("pipex: %s\n", msg);
	else if (file && !msg)
		error_print("pipex: %s: %s\n", file, strerror(error));
	else if (msg && file)
		error_print("pipex: %s: %s\n", file, msg);
	else
		perror("pipex");
	exit (error);
}

void	close_and_free(t_list aux, char **to_free)
{
	close(aux.fd[0]);
	close(aux.fd[1]);
	close(aux.pipefd[0]);
	close(aux.pipefd[1]);
	if (to_free)
	{
		free(aux.cmds[0]);
		free(aux.cmds[1]);
		free_all(to_free);
	}
}
