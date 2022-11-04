/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:27:13 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/12 04:29:04 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *src)
{
	size_t		src_len;
	char		*dest;
	int			i;

	src_len = ft_strlen(src);
	dest = malloc((src_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
