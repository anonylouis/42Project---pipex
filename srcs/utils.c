/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:35:42 by anonylouis        #+#    #+#             */
/*   Updated: 2022/01/16 13:50:47 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_null( char **tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (tab[i] == NULL)
		{
			while (--i >= 0)
				free(tab[i]);
			free(tab);
			return (1);
		}
	}
	return (0);
}

int	is_in_str(char *str, char c)
{
	if (str)
	{
		while (*str)
		{
			if (*str == c)
				return (1);
			str++;
		}
	}
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	if (tab)
	{
		i = -1;
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}	
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}
