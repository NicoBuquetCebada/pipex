/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:51:43 by nico              #+#    #+#             */
/*   Updated: 2025/03/02 17:47:44 by nbuquet-         ###   ########.fr       */
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

// libft
size_t		ft_strlen(const char *s);
size_t		ft_arrlen(char **s);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		**ft_freearr(char **dst);
char		**ft_split(char const *s, char c);

// pipex
void		ft_error(char *error);

void		ft_cleancmdpaths(char **cmd_paths);
void		ft_cleanargs(char ***args);
void		*ft_cleanpipex(t_pipex *pipex);
t_pipex		*ft_newpipex(void);

char		**ft_parsepaths(const char *envp[], char **cmds);

#endif