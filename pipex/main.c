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
// checker -> valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes -s -q ./pipex ...

static void	ft_father(t_list aux, char **av, char **envp)
{
	char	**splited;

	close(aux.pipefd[0]);
	dup2(aux.fd[0], 0);
	dup2(aux.pipefd[1], 1);
	splited = ft_split(av[2], ' ');
	if (!splited)
	{
		free(aux.cmds[0]);
		free(aux.cmds[1]);
		error_msg(-1, "ft_split failed", NULL);
	}
	close(aux.pipefd[1]);
	close(aux.fd[0]);
	close(aux.fd[1]);
	if(execve(aux.cmds[0], splited, envp) == -1)
		error_print("pipex: %s: command not found\n", av[2]);
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
		free(aux.cmds[0]);
		free(aux.cmds[1]);
		error_msg(-1, "ft_split failed", NULL);
	}
	close(aux.pipefd[0]);
	close(aux.fd[0]);
	close(aux.fd[1]);
	if (execve(aux.cmds[1], splited, envp) == -1)
		error_print("pipex: %s: command not found\n", av[3]);
}

int	main(int ac, char **av, char **envp)
{
	int		pid;
	t_list	aux;
	char	**path;

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
		ft_child(aux, av, envp);
	free(aux.cmds[0]);
	free(aux.cmds[1]);
	free_all(path);
	close(aux.fd[1]);
	close(aux.fd[2]);
}
