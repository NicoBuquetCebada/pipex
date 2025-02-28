/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:58:36 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/02/27 23:35:59 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	t_pipex	*pipex;

	pipex = ft_newpipex();
	if (!pipex)
		ft_error("pipex");
	ft_cleanpipex(pipex);
}
