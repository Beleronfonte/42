/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:04:25 by ofernand          #+#    #+#             */
/*   Updated: 2024/08/12 19:36:59 by ofernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <stddef.h>
# include <stdarg.h>

# define FILE_NOT_FOUND	-1
# define CMD_NOT_FOUND	127
# define NO_PERMISSION	-3
# define INVALID_ARGS	-4
# define FORK_ERROR		-5
# define FORK_ERROR		-5

typedef struct s_list
{
	int		fd[2];
	int		pipefd[2];
	char	*cmds[2];
}				t_list;

t_list	check_files(char **av, t_list aux);
char	**get_path(t_list aux, char **envp);
char	*check_cmd(t_list aux, char *cmd_tested, char **path);
int		ft_strlen(char *str);
int		ft_strlcat(char *dest, char *src, int size);
int		ft_strlcpy(char *dest, char *src, int size);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *str, char c);
int		ft_strncmp(char *s1, char *s2, int n);
void	error_msg(int error, char *msg, char *file);
int		error_print(char const *str, ...);
char	**free_all(char **ptr);
void	close_and_free(t_list aux, char **to_free);
#endif
