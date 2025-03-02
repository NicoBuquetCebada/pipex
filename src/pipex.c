/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:58:36 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/03/02 23:28:58 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], const char *envp[])
{
	t_pipex				*pipex;
	char	*cmds[2];

	pipex = ft_newpipex();
	if (!pipex)
		ft_error("pipex");

	cmds[0] = "c_formatter_42";
	cmds[1] = "wc";
	// CMD PATHS
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
	ft_cleanpipex(pipex);
}
