/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:00:39 by ofernand          #+#    #+#             */
/*   Updated: 2024/08/07 17:38:30 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex file1 cmd1 cmd2 file2
// pipefd[0] -> read || pipefd[1] -> write (meto por write y sale por read)
// pid = 0 es el hijo, el padre hace las acciones de else.
// child hace primer comando
int	main(int ac, char **av, char **envp)
{
	int		pid;
	int		pipefd[2];
	char	**splited;
	char	**path;
	char	*cmds[2];
	int		fd[2];
	int		status;

	if (ac != 5)
		error_msg(-1, "wrong number of arguments\n", NULL);
	check_files(av, fd);
	path = get_path(envp);
	cmds[0] = check_cmd(av[2], path);
	cmds[1] = check_cmd(av[3], path);
	if(pipe(pipefd))
		error_msg(errno, NULL, NULL);
	pid= fork();
	if (pid < 0)
		error_msg(errno, NULL, NULL);
    if (pid == 0)
    {
		close(pipefd[0]);
		dup2(fd[0], 0);
		dup2(pipefd[1], 1);
		splited = ft_split(av[2], ' ');
		if (!splited)
		{
			free_all(cmds);
			error_msg(-1, "ft_split failed", NULL);
		}
		execve(cmds[0], splited, envp);
		free_all(splited);
    }
    else
    {
		wait(&status);
		close(pipefd[1]);
		dup2(fd[1], 1);
		dup2(pipefd[0], 0);
		splited = ft_split(av[3], ' ');
		if (!splited)
		{
			free_all(cmds);
			error_msg(-1, "ft_split failed", NULL);
		}
		execve(cmds[1], splited, envp);
		free_all(splited);
    }
	free_all(cmds);
}
