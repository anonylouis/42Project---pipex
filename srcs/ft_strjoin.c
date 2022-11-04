/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:51:15 by lcalvie           #+#    #+#             */
/*   Updated: 2021/11/28 14:51:16 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	len_strjoin(char const *s1, char const *s2)
{
	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (0);
		return (ft_strlen(s2));
	}
	if (s2 == NULL)
		return (ft_strlen(s1));
	return (ft_strlen(s1) + ft_strlen(s2));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	int		i;
	char	*totalstr;

	total_len = len_strjoin(s1, s2);
	totalstr = malloc((total_len + 1) * sizeof(char));
	if (totalstr == NULL)
		return (NULL);
	total_len = 0;
	if (s1 != NULL)
	{
		i = -1;
		while (s1[++i])
			totalstr[total_len++] = s1[i];
	}
	if (s2 != NULL)
	{
		i = -1;
		while (s2[++i])
			totalstr[total_len++] = s2[i];
	}
	totalstr[total_len] = '\0';
	return (totalstr);
}
