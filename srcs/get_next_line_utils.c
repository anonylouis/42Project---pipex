/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:50:57 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/16 16:05:25 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strndup(char *src, int size)
{
	char		*dest;
	int			i;

	dest = malloc((size + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_concat(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	char	*sfinal;
	int		i;
	int		j;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	sfinal = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (sfinal == NULL)
		return (NULL);
	j = -1;
	i = -1;
	while (++i < lens1)
		sfinal[++j] = s1[i];
	i = -1;
	while (++i < lens2)
		sfinal[++j] = s2[i];
	sfinal[++j] = '\0';
	free(s1);
	free(s2);
	return (sfinal);
}
