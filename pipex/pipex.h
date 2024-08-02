/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:04:25 by ofernand          #+#    #+#             */
/*   Updated: 2024/07/31 12:09:47 by ofernand         ###   ########.fr       */
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

# define	FILE_NOT_FOUND	-1
# define	CMD_NOT_FOUND	127
# define	NO_PERMISSION	-3
# define	INVALID_ARGS	-4
# define	FORK_ERROR		-5
# define	FORK_ERROR		-5


void	check_files(char **av, int *fd);
char	**get_path(char **envp);
char	*check_cmd(char *cmd_tested, char **path);
int		ft_strlen(char *str);
int		ft_strlcat(char *dest, char *src, int size);
int		ft_strlcpy(char *dest, char *src, int size);
char	*ft_strjoin(char *s1, char *s2);
char 	**ft_split(char *str, char c);
int		ft_strncmp(char *s1, char *s2, int n);
void	error_msg(int error, char *msg, char *file);
int		error_print(char const *str, ...);
char	**free_all(char **ptr);
#endif
