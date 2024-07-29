/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofernand <ofernand@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:04:25 by ofernand          #+#    #+#             */
/*   Updated: 2024/07/11 16:04:31 by ofernand         ###   ########.fr       */
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

void	check_files(char **av, int *fd);
char	**get_path(char **envp);
char	*check_cmd(char *cmd_tested, char **path);
//int		error_msg();
int		ft_strlen(char *str);
int		ft_strlcat(char *dest, char *src, int size);
int		ft_strlcpy(char *dest, char *src, int size);
char	*ft_strjoin(char *s1, char *s2);
char 	**ft_split(char *str, char c);
int		ft_strncmp(char *s1, char *s2, int n);
#endif
