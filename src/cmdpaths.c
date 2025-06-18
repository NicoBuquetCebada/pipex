/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdpaths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:02:02 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/06/18 18:24:36 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_pathenv(const char *envp[])
{
	size_t	i;

	if (!envp || !envp[0])
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(ft_strdup(envp[i] + 5), ':'));
	}
	return (NULL);
}

static char	*ft_checkpath(char *env, char *cmd)
{
	char	*path;
	size_t	total_s;

	total_s = ft_strlen(env) + ft_strlen(cmd) + 1;
	path = ft_calloc(total_s + 1, sizeof(char));
	if (!path)
		return (NULL);
	ft_strlcat(path, env, ft_strlen(env) + 1);
	ft_strlcat(path, "/", ft_strlen(env) + 2);
	ft_strlcat(path, cmd, total_s + 1);
	if (access(path, F_OK) == 0)
		return (path);
	free(path);
	return (NULL);
}

static char	**ft_foundpaths(char **paths, char **cmds, char **pathenv)
{
	char	*path;
	size_t	k;
	size_t	i;
	size_t	j;

	i = -1;
	k = 0;
	if (!paths)
		return (NULL);
	while (cmds[++i])
	{
		j = -1;
		while (pathenv[++j])
		{
			path = ft_checkpath(pathenv[j], cmds[i]);
			if (path)
			{
				paths[k++] = path;
				break ;
			}
		}
	}
	paths[k] = NULL;
	return (paths);
}

static int	ft_chekvldty(char **paths, size_t cmds)
{
	if (!paths || cmds != ft_arrlen(paths))
	{
		ft_freearr(paths);
		perror("access");
		return (1);
	}
	return (0);
}

char	**ft_parsepaths(const char *envp[], char **cmds)
{
	char	**pathenv;
	char	**paths;

	if (!cmds)
		return (NULL);
	pathenv = ft_pathenv(envp);
	if (!pathenv)
		return (NULL);
	paths = (char **)malloc((ft_arrlen(cmds) + 1) * sizeof(char *));
	if (!paths)
		return (ft_freearr(pathenv));
	paths = ft_foundpaths(paths, cmds, pathenv);
	ft_freearr(pathenv);
	if (ft_chekvldty(paths, ft_arrlen(cmds)))
		return (NULL);
	return (paths);
}
