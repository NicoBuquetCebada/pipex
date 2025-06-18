/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:35:00 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/06/17 19:26:43 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_getcmds(size_t cmdc, char ***args)
{
	char	**cmds;
	size_t	i;

	cmds = (char **)malloc((cmdc + 1) * sizeof(char *));
	if (!cmds)
		return (NULL);
	i = -1;
	while (args[++i])
		cmds[i] = args[i][0];
	cmds[i] = NULL;
	return (cmds);
}

char	***ft_parseargs(size_t argc, char **argv)
{
	char	***args;
	size_t	i;
	size_t	j;

	if (argc < 5)
		return (NULL);
	args = (char ***)malloc((argc - 3 + 1) * sizeof(char **));
	if (!args)
		return (NULL);
	i = 2;
	j = 0;
	while (i < argc - 1)
	{
		args[j] = ft_split(ft_strdup(argv[i]), ' ');
		if (!args[j])
			return (NULL);
		i++;
		j++;
	}
	args[j] = NULL;
	return (args);
}

char	**ft_parsefiles(char **argv)
{
	char	**files;

	files = (char **)malloc((2 + 1) * sizeof(char *));
	if (!files)
		return (NULL);
	files[0] = argv[1];
	files[1] = argv[4];
	files[3] = NULL;
	return (files);
}
