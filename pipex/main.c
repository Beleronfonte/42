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
		close_and_free(aux, NULL);
		error_msg(-1, "ft_split failed", NULL);
	}
	close(aux.pipefd[1]);
	close(aux.fd[0]);
	close(aux.fd[1]);
	if (aux.cmds[0] == NULL)
	{
		error_print("pipex: %s: command not found\n", splited[0]);
		free_all(splited);
	}
	else
		execve(aux.cmds[0], splited, envp);
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
		close_and_free(aux, NULL);
		error_msg(-1, "ft_split failed", NULL);
	}
	close(aux.pipefd[0]);
	close(aux.fd[0]);
	close(aux.fd[1]);
	if (aux.cmds[1] == NULL)
	{
		error_print("pipex: %s: command not found\n", splited[0]);
		free_all(splited);
	}
	else
		execve(aux.cmds[1], splited, envp);
}

int	main(int ac, char **av, char **envp)
{
	int		pid;
	t_list	aux;
	char	**path;

	if (ac != 5)
		error_msg(-1, "wrong number of arguments\n", NULL);
	aux = check_files(av, aux);
	path = get_path(aux, envp);
	aux.cmds[0] = check_cmd(aux, av[2], path);
	aux.cmds[1] = check_cmd(aux, av[3], path);
	if (pipe(aux.pipefd))
		error_msg(errno, NULL, NULL);
	pid = fork();
	if (pid < 0)
		error_msg(errno, NULL, NULL);
	if (pid == 0)
		ft_child(aux, av, envp);
	else
		ft_father(aux, av, envp);
	close_and_free(aux, path);
	return (0);
}
