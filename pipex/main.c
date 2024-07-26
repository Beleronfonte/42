/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:02:53 by ofernand          #+#    #+#             */
/*   Updated: 2024/07/26 06:04:05 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./pipex file1 cmd1 cmd2 file2
int	main(int ac, char **av, char **envp)
{
	int pid;
	int	pipefd[2];
	char **path;

	if (ac != 5)
		exit(EXIT_FAILURE); //TODO: definir error de argumentos insuficientes o en exceso
	check_files(av);
	path = get_path(envp);
	check_cmds(av, path);
	if(pipe(pipefd)) //pipefd[0] -> read || pipefd[1] -> write (meto pro write y sale por read)
		return (error_msg()); // si pipe ha ido bien devuelve 0, si ha ido mal, -1
	pid= fork();

    // instrucciones que tanto el padre como el hijo harán

	if (pid < 0)
		return (error_msg()); //fallo del fork
    if (pid = 0)
    {
        // instrucciones que solo el proceso hijo hará
		// primero cerramos el lado del pipe que no usará
		close(pipefd[0]);
    }
    else
    {
        // instrucciones que solo el proceso padre hará
		// primero cerramos el lado del pipe que no usará
		close(pipefd[1]);
    }
}


/*
 PSEUDOCODIGO

 -comprobar que file 1 existe
 	*si no, error "file1: No such file or directory"
 - comprobar que file 2 existe
 	*si no, crearlo y continuar.
 - pipe para crear un canal de comunicación entre padre e hijo (se tiene que crear antes de dividir)
 - fork para separar entre padre e hijo
 -
 *
