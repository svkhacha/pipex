/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:08:50 by svkhacha          #+#    #+#             */
/*   Updated: 2022/07/23 20:00:22 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_cmd(char **path, char *absolute_path_cmd)
{
	int		i;
	char	*cmd;
	char	*full_path;

	if (access(absolute_path_cmd, 0) == 0)
		return (absolute_path_cmd);
	i = 0;
	while (path[i])
	{
		full_path = ft_strjoin(path[i], "/");
		cmd = ft_strjoin(full_path, absolute_path_cmd);
		free(full_path);
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

void	execute_cmd_1(t_pipex p, char **argv, char **envp)
{
	dup2(p.fds[1], 1);
	close(p.fds[1]);
	close(p.fds[0]);
	dup2(p.file1, 0);
	close(p.file1);
	p.cmd_args = ft_split(argv[2], ' ');
	p.cmd = check_cmd(p.cmd_6_paths, p.cmd_args[0]);
	if (p.cmd == NULL)
	{
		ft_putstr_fd("Pipex: command not found: ", 2);
		ft_putstr_fd(p.cmd_args[0], 2);
		ft_putstr_fd("\n", 2);
		free_child(p);
		exit (1);
	}
	if (execve(p.cmd, p.cmd_args, envp) == -1)
		exit (1);
}

void	execute_cmd_2(t_pipex p, char **argv, char **envp)
{
	dup2(p.fds[0], 0);
	close(p.fds[1]);
	close(p.fds[0]);
	dup2(p.file2, 1);
	close(p.file2);
	p.cmd_args = ft_split(argv[3], ' ');
	p.cmd = check_cmd(p.cmd_6_paths, p.cmd_args[0]);
	if (p.cmd == NULL)
	{
		ft_putstr_fd("Pipex: command not found: ", 2);
		ft_putstr_fd(p.cmd_args[0], 2);
		ft_putstr_fd("\n", 2);
		free_child(p);
		exit(1);
	}
	if (execve(p.cmd, p.cmd_args, envp) == -1)
		exit(1);
}

void	free_parent(t_pipex p)
{
	int	i;

	close(p.file1);
	close(p.file2);
	i = 0;
	while (p.cmd_6_paths[i])
	{
		free(p.cmd_6_paths[i]);
		i++;
	}
	free(p.cmd_6_paths);
}

void	free_child(t_pipex p)
{
	int	i;

	i = 0;
	while (p.cmd_args[i])
	{
		free(p.cmd_args[i]);
		i++;
	}
	free(p.cmd_args);
	free(p.cmd);
}
