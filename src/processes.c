/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:07:19 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/06/18 18:23:42 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execone(int *fd, int *in, char **cmd_paths, char ***args)
{
	close(fd[0]);
	dup2(in[0], STDIN_FILENO);
	close(in[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(cmd_paths[0], args[0], NULL);
}

void	ft_exectwo(int *fd, int *in, char **cmd_paths, char ***args)
{
	wait(NULL);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(in[1], STDOUT_FILENO);
	close(in[1]);
	execve(cmd_paths[1], args[1], NULL);
}

int	ft_execpipex(char ***args, char **cmd_paths, char **files)
{
	pid_t	pid;
	int		fd[2];
	int		in[2];

	in[0] = open(files[0], O_RDONLY);
	in[1] = open(files[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-2);
	if (pid == 0)
	{
		ft_execone(fd, in, cmd_paths, args);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_exectwo(fd, in, cmd_paths, args);
		exit(EXIT_SUCCESS);
	}
}
