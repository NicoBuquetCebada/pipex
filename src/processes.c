/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:07:19 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/03/06 21:59:03 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_execpipex(char ***args, char **cmd_paths)
{
	pid_t	pid;
	int		fd[2];
	int		in[2];

	in[0] = open("./infile", O_RDONLY);
	in[1] = open("./outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-2);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(in[0], STDIN_FILENO);
		close(in[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(cmd_paths[0], args[0], NULL);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(in[1], STDOUT_FILENO);
		close(in[1]);
		execve(cmd_paths[1], args[1], NULL);
		exit(EXIT_SUCCESS);
	}
}
