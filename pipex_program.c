/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:06:51 by svkhacha          #+#    #+#             */
/*   Updated: 2022/07/25 14:08:14 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	if (argc != 5)
		return (ft_putstr_fd("Pipex: invalid number of arguments\n", 2));
	p.file1 = open(argv[1], O_RDONLY);
	if (p.file1 == -1)
		error_msg(argv[1]);
	p.file2 = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (p.file2 == -1)
		error_msg(argv[argc - 1]);
	if (pipe(p.fds) == -1)
		error_msg("pipe");
	p.cmd_6_paths = ft_split(get_path(envp), ':');
	p.pid1 = check_for_fork();
	if (p.pid1 == 0)
		execute_cmd_1(p, argv, envp);
	p.pid2 = check_for_fork();
	if (p.pid2 == 0)
		execute_cmd_2(p, argv, envp);
	close_pipe(p.fds);
	wait_children(p.pid1, p.pid2);
	free_parent(p);
	return (0);
}
