/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:51:43 by nico              #+#    #+#             */
/*   Updated: 2025/02/27 19:00:39 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
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

void		ft_cleancmdpaths(char **cmd_paths);
void		ft_cleanargs(char ***args);
t_pipex		*ft_newpipex(void);

#endif