/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:58:36 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/03/02 17:51:43 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(/* int argc, char *argv[], const char *envp[] */)
{
	t_pipex				*pipex;
	extern const char	**environ;
	char	*cmds[2];

	pipex = ft_newpipex();
	if (!pipex)
		ft_error("pipex");

	cmds[0] = "c_formatter_42";
	cmds[1] = "wc";
	pipex->cmd_paths = ft_parsepaths(environ, cmds);
	printf("\n* CMD PATHS *\n----------\n");
	for (int i = 0; pipex->cmd_paths[i] != NULL; i++)
	{
		printf("%s\n", pipex->cmd_paths[i]);
	}
	ft_cleanpipex(pipex);
}
