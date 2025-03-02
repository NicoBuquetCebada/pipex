/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:31:23 by nico              #+#    #+#             */
/*   Updated: 2025/03/02 15:19:39 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	i = -1;
	dest = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!dest)
		return (NULL);
	while (s[++i])
		dest[i] = s[i];
	return (dest);
}
