/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:35:00 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/03/02 23:31:40 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	***ft_parseargs(size_t argc, char **argv)
{
	char	***args;
	size_t	i;
	size_t	j;

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
