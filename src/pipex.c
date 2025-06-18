/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:58:36 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/06/18 18:21:52 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], const char *envp[])
{
	t_pipex	*pipex;
	char	**cmds;
	char	**files;
	int		error;

	pipex = ft_newpipex();
	if (!pipex)
		ft_pipexerror(pipex);
	pipex->args = ft_parseargs((size_t)argc, argv);
	if (!pipex->args)
		ft_pipexerror(pipex);
	cmds = ft_getcmds(argc - 3, pipex->args);
	if (!cmds)
		ft_pipexerror(pipex);
	pipex->cmd_paths = ft_parsepaths(envp, cmds);
	if (!pipex->cmd_paths)
		ft_pipexerror(pipex);
	files = ft_parsefiles(argv);
	error = ft_execpipex(pipex->args, pipex->cmd_paths, files);
	if (error == -1)
		ft_error("pipe", pipex);
	if (error == -2)
		ft_error("fork", pipex);
}
