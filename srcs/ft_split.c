/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:59:01 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/16 12:58:10 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(char const *s, char c)
{
	size_t	nb_words;
	size_t	i;

	if (s == NULL)
		return (0);
	nb_words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			nb_words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nb_words);
}

static int	fill_tab(char **to_fill, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = 1;
	i = 0;
	while (s[++i] && s[i] != c)
		len++;
	*to_fill = malloc((len + 1) * sizeof(char));
	if ((*to_fill) == NULL)
		return (len);
	j = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		(*to_fill)[j] = s[i++];
		j++;
	}
	(*to_fill)[len] = '\0';
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	int		i;
	char	**tabstr;

	nb_words = count_words(s, c);
	tabstr = malloc((nb_words + 1) * sizeof(char *));
	if (tabstr == NULL)
		return (NULL);
	i = 0;
	nb_words = 0;
	while (s != NULL && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			i += fill_tab(&(tabstr[nb_words]), &(s[i]), c);
			nb_words++;
		}
	}
	tabstr[nb_words] = NULL;
	if (check_null(tabstr, nb_words))
		return (NULL);
	return (tabstr);
}
