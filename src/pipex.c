/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:58:36 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/03/06 21:26:40 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], const char *envp[])
{
	t_pipex	*pipex;
	char	**cmds;
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
	error = ft_execpipex(pipex->args, pipex->cmd_paths);
	if (error == -1)
		ft_error("pipe", pipex);
	if (error == -2)
		ft_error("fork", pipex);
}
/* 	// CMD PATHS
	for (int i = 0; pipex->cmd_paths[i]; i++)
		printf("%s\n", pipex->cmd_paths[i]);
	for (int i = 0; cmds[i]; i++)
		printf("%s ", cmds[i]);
	pipex->cmd_paths = ft_parsepaths(envp, cmds);
	printf("\n* CMD PATHS *\n----------\n");
	for (int i = 0; pipex->cmd_paths[i]; i++)
	{
		printf("%s\n", pipex->cmd_paths[i]);
	}
	// ARGS
	printf("\n* ARGS *\n----------\n");
	pipex->args =  ft_parseargs((size_t)argc, argv);
	for (int i = 0; pipex->args[i]; i++)
	{
		for (int j = 0; pipex->args[i][j]; j++)
		{
			printf("%s ", pipex->args[i][j]);
		}
		printf("\n");
	}
*/