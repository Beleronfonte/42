/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:00:39 by ofernand          #+#    #+#             */
/*   Updated: 2024/07/31 12:02:25 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex file1 cmd1 cmd2 file2
int	main(int ac, char **av, char **envp)
{
	int		pid;
	int		pipefd[2];
	char	**path;
	char	*cmds[2];
	int		fd[2];

	if (ac != 5)
	//	exit(error_msg(INVALID_ARGS); //TODO: definir error de "wrong number of arguments"
		exit(1);
	check_files(av, fd);
	path = get_path(envp);
	cmds[0] = check_cmd(av[2], path); //habra que liberarlos, no?
	cmds[1] = check_cmd(av[3], path);
	if(pipe(pipefd)) //pipefd[0] -> read || pipefd[1] -> write (meto por write y sale por read)
		return (0);
		//return (error_msg()); // si pipe ha ido bien devuelve 0, si ha ido mal, -1
	pid= fork();
	if (pid < 0)
		exit(1);	
		//return (error_msg(FORK_ERROR)); //TODO:fallo del fork
    if (pid == 0) // instrucciones que solo el proceso hijo hará
    {
		close(pipefd[1]);// primero cerramos el lado del pipe que no usará: escritura
		dup2(pipefd[0], 0); //hago que el STDIN sea el file1 a traves del pipe
		dup2(fd[1], 1); //hago que el STDOUT sea el file2
		execve(cmds[1], &av[3], envp);
    }
    else // instrucciones que solo el proceso padre hará
    {
		close(pipefd[0]);// primero cerramos el lado del pipe que no usará
		dup2(fd[0], 0); //hago que el STDIN sea el file1
		dup2(pipefd[1], 1); //hago que el STDOUT sea el pipe
		execve(cmds[0], &av[2], envp);
    }
}
