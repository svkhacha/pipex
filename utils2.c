/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:50:57 by svkhacha          #+#    #+#             */
/*   Updated: 2022/07/23 16:00:40 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *str)
{
	char	*error;

	error = strerror(errno);
	ft_putstr_fd("Pipex: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

char	*get_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

pid_t	check_for_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(1);
	return (pid);
}	

void	close_pipe(int fds[2])
{
	close(fds[0]);
	close(fds[1]);
}

void	wait_children(pid_t pid1, pid_t pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
