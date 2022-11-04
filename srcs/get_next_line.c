/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:00:16 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/16 16:12:37 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_line(char **line)
{
	free(*line);
	*line = NULL;
}

char	*ft_substr(char *line, int start)
{
	int		i;
	int		j;
	int		len;
	char	*substr;

	len = ft_strlen(line + start);
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = start;
	j = -1;
	while (++j < len)
		substr[j] = line[i + j];
	substr[len] = '\0';
	free(line);
	return (substr);
}

char	*ft_find_next_line(char *line, char **res)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		*res = ft_strndup(line, i + 1);
		line = ft_substr(line, i + 1);
	}
	else
	{
		*res = ft_strndup(line, i);
		free(line);
		line = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			nb_byte_read;
	static char	*line;
	char		*res;

	if (line == NULL || line[0] == '\0')
	{
		ft_free_line(&line);
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer != NULL)
			nb_byte_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer == NULL || nb_byte_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		line = ft_strndup(buffer, nb_byte_read);
		free(buffer);
	}
	line = ft_find_next_line(line, &res);
	if (line == NULL)
		res = ft_concat(res, get_next_line(fd));
	if (line[0] == '\0')
		ft_free_line(&line);
	return (res);
}
