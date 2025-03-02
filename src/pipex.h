/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:51:43 by nico              #+#    #+#             */
/*   Updated: 2025/03/02 23:09:23 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		in;
	int		out;
	char	**cmd_paths;
	char	***args;
}			t_pipex;

void		ft_error(char *error);

void		ft_cleancmdpaths(char **cmd_paths);
void		ft_cleanargs(char ***args);
void		*ft_cleanpipex(t_pipex *pipex);
t_pipex		*ft_newpipex(void);

char		***ft_parseargs(size_t argc, char **argv);
char		**ft_parsepaths(const char *envp[], char **cmds);

#endif