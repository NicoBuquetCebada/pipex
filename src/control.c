/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:07:09 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/03/06 20:02:59 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *error, t_pipex *pipex)
{
	ft_cleanpipex(pipex);
	perror(error);
	exit(EXIT_FAILURE);
}

void	ft_success(t_pipex *pipex, char **cmds)
{
	ft_freearr(cmds);
	ft_cleanpipex(pipex);
	exit(EXIT_SUCCESS);
}
