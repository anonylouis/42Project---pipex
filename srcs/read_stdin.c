/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:09:19 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/17 00:16:11 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_stdin(t_pipex *pipex)
{
	char	*line;
	int		len;
	int		pipefds[2];

	if (pipe(pipefds) == -1)
		perror("pipe");
	len = ft_strlen(pipex->limiter);
	ft_putstr_fd("pipe heredoc> ", 1);
	line = get_next_line(0);
	while (line
		&& !(ft_strncmp(line, pipex->limiter, len) == 0
			&& (int) ft_strlen(line) == len + 1
			&& line[len] == '\n'))
	{
		ft_putstr_fd(line, pipefds[1]);
		free(line);
		ft_putstr_fd("pipe heredoc> ", 1);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	if (close(pipefds[1]))
		perror("close");
	pipex->fd_infile = pipefds[0];
}
