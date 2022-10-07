/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:57:34 by svkhacha          #+#    #+#             */
/*   Updated: 2022/07/25 14:18:04 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h> //errno
# include <string.h> //strerror 
# include <unistd.h> // access, execve, fork, pipe, close, dup2
# include <stdio.h> // 
# include <sys/wait.h> // waitpid
# include <sys/types.h> // pid_t
# include <sys/uio.h> // iovec struct
# include <stdlib.h> // exit, malloc, free
# include <fcntl.h> // flags (O_RDWR, O_RDONLY, O_CREAT, O_TRUNC), open

typedef struct s_pipex
{
	int		file1;
	int		file2;
	int		fds[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
	char	**cmd_args;
	char	**cmd_6_paths;	
}			t_pipex;

char	*check_cmd(char **path, char *absolute_path_cmd);
char	*ft_strjoin(char *s1, char *s2);
char	*get_path(char **envp);
char	**ft_split(char *str, char c);

void	execute_cmd_1(t_pipex p, char **argv, char **envp);
void	execute_cmd_2(t_pipex p, char **argv, char **envp);
void	error_msg(char *str);
void	close_pipe(int fds[2]);
void	wait_children(pid_t pid1, pid_t pid2);
void	free_parent(t_pipex p);
void	free_child(t_pipex p);

int		ft_strlen(char *str);
int		ft_putstr_fd(char *str, int fd);
int		ft_strncmp(char *s1, char *s2, size_t n);

pid_t	check_for_fork(void);

#endif
