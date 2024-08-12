/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:00:39 by ofernand          #+#    #+#             */
/*   Updated: 2024/08/12 19:42:08 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex file1 cmd1 cmd2 file2
// pipefd[0] -> read || pipefd[1] -> write (meto por write y sale por read)
// pid = 0 es el hijo, el padre hace las acciones de else.
// child hace primer comando

static void	ft_father(t_list aux, char **av, char **envp)
{
	char	**splited;

	close(aux.pipefd[0]);
	dup2(aux.fd[0], 0);
	dup2(aux.pipefd[1], 1);
	splited = ft_split(av[2], ' ');
	if (!splited)
	{
		free_all(aux.cmds);
		error_msg(-1, "ft_split failed", NULL);
	}
	execve(aux.cmds[0], splited, envp);
	free_all(splited);
}

static void	ft_child(t_list aux, char **av, char **envp)
{
	char	**splited;

	close(aux.pipefd[1]);
	dup2(aux.fd[1], 1);
	dup2(aux.pipefd[0], 0);
	splited = ft_split(av[3], ' ');
	if (!splited)
	{
		free_all(aux.cmds);
		error_msg(-1, "ft_split failed", NULL);
	}
	execve(aux.cmds[1], splited, envp);
	free_all(splited);
}

int	main(int ac, char **av, char **envp)
{
	int		pid;
	t_list	aux;
	char	**path;
	int		status;

	if (ac != 5)
		error_msg(-1, "wrong number of arguments\n", NULL);
	aux = check_files(av, aux);
	path = get_path(envp);
	aux.cmds[0] = check_cmd(av[2], path);
	aux.cmds[1] = check_cmd(av[3], path);
	if (pipe(aux.pipefd))
		error_msg(errno, NULL, NULL);
	pid = fork();
	if (pid < 0)
		error_msg(errno, NULL, NULL);
	if (pid == 0)
		ft_father(aux, av, envp);
	else
	{
		wait(&status);
		ft_child(aux, av, envp);
	}
	free_all(aux.cmds);
}
