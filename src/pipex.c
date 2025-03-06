/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:58:36 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/03/06 20:03:48 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], const char *envp[])
{
	t_pipex	*pipex;
	char	**cmds;
	
	pipex = ft_newpipex();
	if (!pipex)
		ft_error("pipex", pipex);
	pipex->args = ft_parseargs((size_t)argc, argv);
	if (!pipex->args)
		ft_error("pipex", pipex);
	cmds = ft_getcmds(argc - 3, pipex->args);
	if (!cmds)
		ft_error("pipex", pipex);
	pipex->cmd_paths = ft_parsepaths(envp, cmds);
	if (!pipex->cmd_paths)
		ft_error("pipex", pipex);
	ft_success(pipex, cmds);
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
	} */